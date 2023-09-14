#include "../include/averager.h"

static void analyse_error_log_file(char line[CMD_LEN], char cmd[CMD_LEN]);
static void five_hundred_sorted_elements();
static void hundred_sorted_elements();
static void fifty_sorted_elements();
static void nine_sorted_elements();
static void four_sorted_elements();
static void single_sorted_element();
static void exec_cmd_and_analyse_output();

int main(void) {
    char output[CMD_LEN];
    static void (*tests[])(char[]) = {
        single_sorted_element, four_sorted_elements, nine_sorted_elements,
		fifty_sorted_elements, hundred_sorted_elements, five_hundred_sorted_elements, NULL
	};
	exec_each_void_param_function_in(tests);
}

static void single_sorted_element() {
    FILE *fp;
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d 2>&1", 42);
    printf(CYAN "single_sorted_element ------ " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void four_sorted_elements() {
    FILE *fp;
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d 2>&1", 0, 1, 2, 3);
    printf(CYAN "four_sorted_elements ------- " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void nine_sorted_elements() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d %d %d %d %d %d 2>&1",
            0, 1, 2, 3, 4, 5, 6, 7, 8);
    printf(CYAN "nine_sorted_elements ------- " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void fifty_sorted_elements() {
    int i;
    char buffer[5];
	char cmd[MEDIUM_CMD_LEN];
    strcpy(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap ");
    for (i = 0; i < 50; i++) {
        sprintf(buffer, " %d", i);
        strcat(cmd, buffer);
    }
    strcat(cmd, " 2>&1");
    printf(CYAN "fifty_sorted_elements ------ " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void hundred_sorted_elements() {
    int i;
    char buffer[5];
	char cmd[MEDIUM_CMD_LEN];
    strcpy(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap ");
    for (i = 0; i < 100; i++) {
        sprintf(buffer, " %d", i);
        strcat(cmd, buffer);
    }
    strcat(cmd, " 2>&1");
    printf(CYAN "hundred_sorted_elements ---- " DEF_COLOR);
    exec_cmd_and_analyse_output(cmd);
}

static void five_hundred_sorted_elements() {
    int i;
    char buffer[5];
	char cmd[BIG_CMD_LEN];
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
    analyse_cmd_output(line, fp, cmd, !BONUS);
    pclose(fp);
    return;
}
