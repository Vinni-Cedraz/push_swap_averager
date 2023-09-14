#include "../include/averager.h"

void b_no_args() {
    char cmd[CMD_LEN];
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker) 2>&1");
    printf(CYAN "no_args      " DEF_COLOR "cmd -> ./checker              ");
    exec_test_and_analyse_output(cmd, CMD_OUTPUT, BONUS);
    system("rm -f error.log");
}

void b_empty_string() {
    char cmd[CMD_LEN];
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker \"%s\") 2>error.log", "");
    printf(CYAN "empty string " DEF_COLOR "cmd -> ./checker \"\"           ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric1() {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1,
            "9a");
    printf(CYAN "non_numeric  " DEF_COLOR "cmd -> ./checker 3 2 1 9a     ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric2() {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1, "a");
    printf(CYAN "non_numeric  " DEF_COLOR "cmd -> ./checker 3 2 1 a      ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric3() {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1,
            "12 a 2");
    printf(CYAN "non_numeric  " DEF_COLOR "cmd -> ./checker 3 2 1 12 a 2 ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric4() {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1,
            "12 - 2");
    printf(CYAN "non_numeric  " DEF_COLOR "cmd -> ./checker 3 2 1 12 - 2 ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric5() {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1,
            "12 --2");
    printf(CYAN "non_numeric  " DEF_COLOR "cmd -> ./checker 3 2 1 12 --2 ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric6() {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1,
            "12 ++2");
    printf(CYAN "non_numeric  " DEF_COLOR "cmd -> ./checker 3 2 1 12 ++2 ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_max_int_overf() {
    char cmd[CMD_LEN];
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %lu) 2>error.log", 35, 24, 21,
            21474836498);
    printf(CYAN "max_int_overf" DEF_COLOR "      cmd -> ./checker 35 24 21 21474836498               ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_duplicate_sorted() {
	char cmd[CMD_LEN];
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %d %d %d) 2>error.log", 10,
            11, 12, 13, 14, 14);
    printf(CYAN "duplicate_sorted" DEF_COLOR "   cmd -> ./checker 10, 11, 12, 13, 14, 14             ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_invalid_action() {
	char cmd[CMD_LEN];
    sprintf(cmd, "(cat cmds | valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %d %d %d) 2>error.log",
            11, 10, 12, 13, 14, 15);
    printf(CYAN "invalid_action" DEF_COLOR "     cmd -> cat cmds | ./checker 11, 10, 12, 13, 14, 15  ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_duplicate_arg() {
	char cmd[CMD_LEN];
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d) 2>error.log", 1, 2, 1);
    dprintf(1, CYAN "duplicate_args" DEF_COLOR "     cmd -> ./checker 1 2 1                              ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_whitespaced_action() {
	char cmd[CMD_LEN];
    sprintf(cmd, "(cat cmds2 | valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %d %d %d) 2>error.log",
            11, 10, 12, 13, 14, 15);
    printf(CYAN "whitespaced_action" DEF_COLOR " cmd -> cat cmds2 | ./checker 11, 10, 12, 13, 14, 15 ");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}
