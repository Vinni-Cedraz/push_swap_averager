#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_EXPECTED 1
#define EMPTY_NOT_EXPECTED 0
#define WHITE "\033[1;97m"
#define HCYAN "\033[1;36m"
#define CYAN "\033[0;36m"
#define DEF_COLOR "\033[0;39m"
#define GREEN "\033[0;32m"
#define HRED "\033[1;31m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"

static void get_test_output(char *cmd, bool empty_expected);
static void log_error(bool empty_expected, char *out_str, char *cmd);
static void no_args(char *cmd);
static void empty_string(char *cmd);
static void whitespaced_action(char *cmd);
static void duplicate_arg(char *cmd);
static void duplicate_sorted(char *cmd);
static void max_int_overf(char *cmd);
static void non_numeric(char *cmd);
static void trim_linebreak(char *str);

int main(void) {
    char *cmd;
    FILE *fp = NULL;
    char *output;

    cmd = calloc(sizeof(char), 8000);
    output = calloc(sizeof(char), 8000);

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

    free(output);
    free(cmd);
}

static void get_test_output(char *cmd, bool empty_expected) {
    size_t len = 0;
    ssize_t read;
    char *line = calloc(500, sizeof(char));

    if (empty_expected) {
        FILE *fp = popen(cmd, "r");

        if (fp == NULL) {
            perror("popen");
            exit(errno);
        }

        char *out_str = fgets(line, 100, fp);
        if (NULL == out_str) {
            printf(GREEN "OK" DEF_COLOR "	<-	");
            printf("%s\n", cmd);
        } else
            log_error(EMPTY_EXPECTED, out_str, cmd);
        free(out_str);
        pclose(fp);
        return;
    }

    if (!empty_expected) {
        FILE *fp = popen(cmd, "r");
        pclose(fp);
        FILE *error_log = fopen("error.log", "r");
        if ((read = getline(&line, &len, error_log)) != -1) {
            if (strcmp(line, "Error\n") == 0) {
                printf(GREEN "OK" DEF_COLOR "	<-	");
                printf("%s\n", cmd);
            } else
                log_error(EMPTY_NOT_EXPECTED, line, cmd);
        } else
            log_error(EMPTY_NOT_EXPECTED, line, cmd);
        fclose(error_log);
    }
    free(line);
}

static void no_args(char *cmd) {
    sprintf(cmd, "valgrind -q ./push_swap 2>&1");
    get_test_output(cmd, 1);
    system("rm -f error.log");
}

static void empty_string(char *cmd) {
    sprintf(cmd, "valgrind -q ./push_swap %s 2>&1", "");
    get_test_output(cmd, 1);
    system("rm -f error.log");
}

static void non_numeric(char *cmd) {
    sprintf(cmd, "valgrind -q ./push_swap %d %d %d %s 2>error.log", 3, 2, 1,
            "9a");
    get_test_output(cmd, 0);
    system("rm -f error.log");
}

static void max_int_overf(char *cmd) {
    sprintf(cmd, "valgrind -q ./push_swap %d %d %d %lu 2>error.log", 35, 24, 21,
            21474836498);
    get_test_output(cmd, 0);
    system("rm -f error.log");
}

static void duplicate_sorted(char *cmd) {
    sprintf(cmd, "valgrind -q ./push_swap %d %d %d %d %d %d 2>error.log", 10,
            11, 12, 13, 14, 14);
    get_test_output(cmd, 0);
    system("rm -f error.log");
}

static void duplicate_arg(char *cmd) {
    sprintf(cmd, "valgrind -q ./push_swap %d %d %d 2>error.log", 1, 2, 1);
    get_test_output(cmd, 0);
    system("rm -f error.log");
}

static void trim_linebreak(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}

static void log_error(bool empty_expected, char *out_str, char *cmd) {
    trim_linebreak(out_str);
    if (empty_expected) {
        printf(cmd);
        printf(HRED " KO" DEF_COLOR);
        printf(RED
               "	Expected nothing either on stderr nor on stdout (fd "
               "1 or 2)" DEF_COLOR);
        printf(BLUE "	Got" DEF_COLOR " \"" DEF_COLOR " \%s\"" BLUE
                    " instead\n" DEF_COLOR,
               out_str);
    } else if (!empty_expected) {
        printf(cmd);
        printf(HRED " KO" DEF_COLOR);
        printf(RED
               "	Expected the string \"Error\\n\" on the stderr (fd "
               "2)");
        printf(BLUE "	Got" DEF_COLOR " \"" DEF_COLOR " \%s\"" BLUE
                    " instead\n" DEF_COLOR,
               out_str);
    }
}
