#include "../include/averager.h"

void no_args(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q %s 2>&1", program_name);
    printf(CYAN "no_args ------------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, CMD_OUTPUT, !BONUS);
    system("rm -f error.log");
}

void non_numeric1(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d %s 2>error.log",
            program_name, 3, 2, 1, "9a");
    printf(CYAN "non_numeric 1 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void non_numeric2(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d %s 2>error.log",
            program_name, 3, 2, 1, "a");
    printf(CYAN "non_numeric 2 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void non_numeric3(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d %s 2>error.log",
            program_name, 3, 2, 1, "12 a 2");
    printf(CYAN "non_numeric 3 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void non_numeric4(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d %s 2>error.log",
            program_name, 3, 2, 1, "12 - 2");
    printf(CYAN "non_numeric 4 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void non_numeric5(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d %s 2>error.log",
            program_name, 3, 2, 1, "12 --2");
    printf(CYAN "non_numeric 5 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void non_numeric6(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d %s 2>error.log",
            program_name, 3, 2, 1, "12 ++2");
    printf(CYAN "non_numeric 6 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void non_numeric_empty_string(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q %s \"%s\" 2>error.log", program_name, "");
    printf(CYAN "empty_string -------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void max_int_overf(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d %lu 2>error.log",
            program_name, 35, 24, 21, 21474836498);
    printf(CYAN "max_int_overf ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void duplicate_arguments(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d 2>error.log",
            program_name, 1, 2, 1);
    printf(CYAN "duplicate_arguments - " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

void duplicate_sorted(char *program_name) {
    char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all"
            " -q %s %d %d %d %d %d %d 2>error.log",
            program_name, 10, 11, 12, 13, 14, 14);
    printf(CYAN "duplicate_sorted ---- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}
