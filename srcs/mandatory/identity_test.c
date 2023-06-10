#include "../include/averager.h"

static void analyse_cmd_output(char line[500], FILE *fp, char cmd[500]);
static void analyse_error_log_file(char line[500], char cmd[500]);
static void nine_sorted_elements(char *cmd, char *output);
static void four_sorted_elements(char *cmd, char *output);
static void single_sorted_element(char *cmd, char *output);

int main(void) {
    char cmd[500];
    char output[500];

    single_sorted_element(cmd, output);
    four_sorted_elements(cmd, output);
    nine_sorted_elements(cmd, output);
}

static void exec_cmd_and_analyse_output(char *cmd) {
    char line[500];
    FILE *fp;
    open_process_and_exec_cmd_there(&fp, cmd, DONT_CLOSE_PROCESS_AFTER);
    analyse_cmd_output(line, fp, cmd);
    pclose(fp);
    return;
}

static void analyse_cmd_output(char line[500], FILE *fp, char cmd[500]) {
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

static void single_sorted_element(char *cmd, char *output) {
    FILE *fp;
    sprintf(cmd,
            "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap "
            "%d 2>&1",
            42);
    printf(CYAN "single_sorted_element ------ " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void four_sorted_elements(char *cmd, char *output) {
    FILE *fp;
    sprintf(cmd,
            "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap "
            "%d %d %d "
            "%d 2>&1",
            0, 1, 2, 3);
    printf(CYAN "four_sorted_elements  ------ " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void nine_sorted_elements(char *cmd, char *output) {
    sprintf(cmd,
            "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap "
            "%d %d %d "
            "%d %d %d %d %d %d 2>&1",
            0, 1, 2, 3, 4, 5, 6, 7, 8);
    printf(CYAN "nine_sorted_elements  ------ " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}
