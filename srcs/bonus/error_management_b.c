#include "../include/averager.h"

void b_no_args(char *cmd) {
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker) 2>&1");
    exec_test_and_analyse_output(cmd, CMD_OUTPUT, BONUS);
    system("rm -f error.log");
}

void b_empty_string(char *cmd) {
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker \"%s\") 2>error.log", "");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric1(char *cmd) {
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1, "9a");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric2(char *cmd) {
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1, "a");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric3(char *cmd) {
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1, "12 a 2");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric4(char *cmd) {
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1, "12 - 2");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric5(char *cmd) {
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1, "12 --2");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_non_numeric6(char *cmd) {
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %s 2>error.log", 3, 2, 1, "12 ++2");
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_max_int_overf(char *cmd) {
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %lu) 2>error.log",
			35, 24, 21, 21474836498);
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_duplicate_sorted(char *cmd) {
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %d %d %d) 2>error.log",
            10, 11, 12, 13, 14, 14);
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_invalid_action(char *cmd) {
    sprintf(cmd, "(cat cmds | valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %d %d %d) 2>error.log",
            11, 10, 12, 13, 14, 15);
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_duplicate_arg(char *cmd) {
    sprintf(cmd, "(valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d) 2>error.log",
            1, 2, 1);
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}

void b_whitespaced_action(char *cmd) {
    sprintf(cmd, "(cat cmds2 | valgrind --leak-check=full --show-leak-kinds=all -q ./checker %d %d %d %d %d %d) 2>error.log",
            11, 10, 12, 13, 14, 15);
    exec_test_and_analyse_output(cmd, LOG_FILE, BONUS);
    system("rm -f error.log");
}
