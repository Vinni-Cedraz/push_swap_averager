#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_EXPECTED 1
#define EMPTY_NOT_EXPECTED 0
#define CLOSE_PROCESS_AFTER 1
#define DONT_CLOSE_PROCESS_AFTER 0
#define WHITE "\033[1;97m"
#define HCYAN "\033[1;36m"
#define CYAN "\033[0;36m"
#define DEF_COLOR "\033[0;39m"
#define GREEN "\033[0;32m"
#define HRED "\033[1;31m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"

static void get_test_output(char *cmd, bool empty_expected);
static void analyse_cmd_output(char line[500], FILE *fp, char cmd[500]);
static void log_error(bool empty_expected, char *out_str, char *cmd);
static void analyse_error_log_file(char line[500], char cmd[500]);
static void no_args(char *cmd);
static void empty_string(char *cmd);
static void whitespaced_action(char *cmd);
static void duplicate_arg(char *cmd);
static void duplicate_sorted(char *cmd);
static void max_int_overf(char *cmd);
static void non_numeric(char *cmd);
static void open_process_and_exec_cmd_there(FILE **fp, char *cmd, bool close);
static void trim_linebreak(char *str);

int main(void) {
    char cmd[500];
    char output[500];

    printf(CYAN "no_args		 ------  " DEF_COLOR);
    no_args(cmd);
    printf(CYAN "empty string	 ------  " DEF_COLOR);
    empty_string(cmd);
    printf(CYAN "non_numeric	 ------  " DEF_COLOR);
    non_numeric(cmd);
    printf(CYAN "max_int_overf	 ------  " DEF_COLOR);
    max_int_overf(cmd);
    printf(CYAN "duplicate_sorted ------  " DEF_COLOR);
    duplicate_sorted(cmd);
}

static void no_args(char *cmd) {
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all "
                 " -q ./push_swap 2>&1");
    get_test_output(cmd, 1);
    system("rm -f error.log");
}

static void empty_string(char *cmd) {
    sprintf(cmd,
            "valgrind --leak-check=full --show-leak-kinds=all "
            " -q ./push_swap %s 2>&1",
            "");
    get_test_output(cmd, 1);
    system("rm -f error.log");
}

static void non_numeric(char *cmd) {
    sprintf(cmd,
            "valgrind --leak-check=full --show-leak-kinds=all "
            " -q ./push_swap %d %d %d %s 2>error.log",
            3, 2, 1, "9a");
    get_test_output(cmd, 0);
    system("rm -f error.log");
}

static void max_int_overf(char *cmd) {
    sprintf(cmd,
            "valgrind --leak-check=full --show-leak-kinds=all "
            " -q ./push_swap %d %d %d %lu 2>error.log",
            35, 24, 21, 21474836498);
    get_test_output(cmd, 0);
    system("rm -f error.log");
}

static void duplicate_sorted(char *cmd) {
    sprintf(cmd,
            "valgrind --leak-check=full --show-leak-kinds=all "
            " -q ./push_swap %d %d %d %d %d %d 2>error.log",
            10, 11, 12, 13, 14, 14);
    get_test_output(cmd, 0);
    system("rm -f error.log");
}

static void duplicate_arg(char *cmd) {
    sprintf(cmd,
            "valgrind --leak-check=full --show-leak-kinds=all "
            " -q ./push_swap %d %d %d 2>error.log",
            1, 2, 1);
    get_test_output(cmd, 0);
    system("rm -f error.log");
}

static void get_test_output(char *cmd, bool empty_expected) {
    char line[500];
    FILE *fp;
    if (empty_expected) {
        open_process_and_exec_cmd_there(&fp, cmd, DONT_CLOSE_PROCESS_AFTER);
        analyse_cmd_output(line, fp, cmd);
        pclose(fp);
        return;
    }
    if (!empty_expected) {
        open_process_and_exec_cmd_there(&fp, cmd, CLOSE_PROCESS_AFTER);
        analyse_error_log_file(line, cmd);
        return;
    }
}

void analyse_cmd_output(char line[500], FILE *fp, char cmd[500]) {
    char *out_str = fgets(line, 100, fp);
    if (out_str) {
        if (NULL != strstr("egmentation", out_str))
            printf(RED "KO" DEF_COLOR "	<---- SEGFAULT on %s\n", cmd), exit(1);
        else if (NULL != strstr("memcheck", out_str))
            printf(RED "KO" DEF_COLOR "	<---- MEMORY LEAK on %s\n", cmd);
    }
    if (NULL == out_str) {
        printf(GREEN "OK" DEF_COLOR " <---- ");
        printf("%s\n", cmd);
    } else
        log_error(EMPTY_EXPECTED, out_str, cmd);
    free(out_str);
}

void analyse_error_log_file(char line[500], char cmd[500]) {
    ssize_t read;
    FILE *error_log = fopen("error.log", "r");
    if ((read = fread(line, sizeof(char), 500, error_log)) != -1) {
        if (!strcmp(line, "Error\n")) {
            printf(GREEN "OK" DEF_COLOR " <---- ");
            printf("%s\n", cmd);
        } else if (NULL != strstr(line, "egmentation"))
            printf(RED "KO" DEF_COLOR "	<---- SEGFAULT\n"), exit(1);
        else if (NULL != strstr(line, "memcheck"))
            printf(RED "KO" DEF_COLOR "	<---- MEMORY LEAK on %s\n", cmd);
    } else
        log_error(EMPTY_NOT_EXPECTED, line, cmd);
    fclose(error_log);
}

static void open_process_and_exec_cmd_there(FILE **fp, char *cmd, bool close) {
    *fp = popen(cmd, "r");
    if (*fp == NULL) {
        perror("popen");
        exit(errno);
    }
    if (close)
        pclose(*fp);
}

static void log_error(bool empty_expected, char *out_str, char *cmd) {
    trim_linebreak(out_str);
    if (empty_expected) {
        printf(cmd);
        printf(HRED " KO" DEF_COLOR);
        printf(RED "	Expected nothing either on stderr nor on stdout (fd "
                   "1 or 2)" DEF_COLOR);
        printf(BLUE "	Got" DEF_COLOR " \"" DEF_COLOR " \%s\"" BLUE
                    " instead\n" DEF_COLOR,
               out_str);
    } else if (!empty_expected) {
        printf(cmd);
        printf(HRED " KO" DEF_COLOR);
        printf(RED "	Expected the string \"Error\\n\" on the stderr (fd "
                   "2)");
        printf(BLUE "	Got" DEF_COLOR " \"" DEF_COLOR " \%s\"" BLUE
                    " instead\n" DEF_COLOR,
               out_str);
    }
}

static void trim_linebreak(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}
