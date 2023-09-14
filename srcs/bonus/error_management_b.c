#include "../include/averager.h"

void b_invalid_action(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "(cat cmds | valgrind --leak-check=full --show-leak-kinds=all -q %s %d %d %d %d %d %d) 2>error.log",
            program_name, 11, 10, 12, 13, 14, 15);
    printf(CYAN "invalid_action ------ " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void b_whitespaced_action(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "(cat cmds2 | valgrind --leak-check=full --show-leak-kinds=all -q %s %d %d %d %d %d %d) 2>error.log",
            program_name, 11, 10, 12, 13, 14, 15);
    printf(CYAN "whitespaced_action -- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}
