#include "../include/averager.h"

static void analyse_cmd_output(char line[CMD_LEN], FILE *fp, char cmd[CMD_LEN]);
static void analyse_error_log_file(char line[CMD_LEN], char cmd[CMD_LEN]);
static void five_hundred_sorted_elements(char *cmd);
static void hundred_sorted_elements(char *cmd);
static void fifty_sorted_elements(char *cmd);
static void nine_sorted_elements(char *cmd);
static void four_sorted_elements(char *cmd);
static void single_sorted_element(char *cmd);
static void exec_cmd_and_analyse_output(char *cmd);
static void exec_each_function_in(void (*array_of_function_ptrs[])(char *));

int main(void) {
    char output[CMD_LEN];
    static void (*tests[])(char[]) = {
        single_sorted_element, four_sorted_elements, nine_sorted_elements,
		fifty_sorted_elements, hundred_sorted_elements, five_hundred_sorted_elements, NULL
	};
	exec_each_function_in(tests);
}

static void exec_each_function_in(void (*array_of_function_ptrs[])(char *)) {
    char cmd[BIG_CMD_LEN] = {0};
    while (*array_of_function_ptrs)
        (*array_of_function_ptrs++)(cmd);
}

static void single_sorted_element(char *cmd) {
    FILE *fp;
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d 2>&1", 42);
    printf(CYAN "single_sorted_element ------ " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void four_sorted_elements(char *cmd) {
    FILE *fp;
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d 2>&1", 0, 1, 2, 3);
    printf(CYAN "four_sorted_elements ------- " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void nine_sorted_elements(char *cmd) {
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d %d %d %d %d %d 2>&1",
            0, 1, 2, 3, 4, 5, 6, 7, 8);
    printf(CYAN "nine_sorted_elements ------- " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void fifty_sorted_elements(char *cmd) {
    int i;
    char buffer[5];
    strcpy(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap ");
    for (i = 0; i < 50; i++) {
        sprintf(buffer, " %d", i);
        strcat(cmd, buffer);
    }
    strcat(cmd, " 2>&1");
    printf(CYAN "fifty_sorted_elements ------ " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void hundred_sorted_elements(char *cmd) {
    int i;
    char buffer[5];
    strcpy(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap ");
    for (i = 0; i < 100; i++) {
        sprintf(buffer, " %d", i);
        strcat(cmd, buffer);
    }
    strcat(cmd, " 2>&1");
    printf(CYAN "hundred_sorted_elements ---- " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void five_hundred_sorted_elements(char *cmd) {
    int i;
    char buffer[5];
    strcpy(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap ");
    for (i = 0; i < 500; i++) {
        sprintf(buffer, " %d", i);
        strcat(cmd, buffer);
    }
    strcat(cmd, " 2>&1");
    printf(CYAN "five_hundred_sorted_elements " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void exec_cmd_and_analyse_output(char *cmd) {
    FILE *fp;
    char line[CMD_LEN];
    open_process_and_exec_cmd_there(&fp, cmd, DONT_CLOSE_PROCESS_AFTER);
    analyse_cmd_output(line, fp, cmd);
    pclose(fp);
    return;
}

static void analyse_cmd_output(char line[500], FILE *fp, char cmd[500]) {
    char *out_str = fgets(line, 100, fp);
    switch (NULL != out_str) {
    case TRUE:
        if (strstr("egmentation", out_str))
            printf(RED "KO" DEF_COLOR "	<---- SEGFAULT on %s\n", cmd), exit(1);
        else if (strstr("memcheck", out_str))
            printf(RED "KO" DEF_COLOR "	<---- MEMORY LEAK on %s\n", cmd);
		break ;
    case FALSE:
        printf(GREEN "OK" DEF_COLOR " <---- ");
        printf("%s\n", cmd);
    }
}
