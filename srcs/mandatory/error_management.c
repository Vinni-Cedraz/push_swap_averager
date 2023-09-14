#include "../include/averager.h"

static void no_args(void);
static void empty_string(void);
static void whitespaced_action(void);
static void duplicate_arguments(void);
static void duplicate_sorted(void);
static void max_int_overf(void);
static void non_numeric1(void);
static void non_numeric2(void);
static void non_numeric3(void);
static void non_numeric4(void);
static void non_numeric5(void);
static void non_numeric6(void);
static void non_numeric_empty_string(void);
static void analyse_error_log_file(char line[500], char cmd[500]);

int main(void) {
    static void (*test[])() = {
        no_args,       non_numeric1,     non_numeric2,        non_numeric3,
        non_numeric4,  non_numeric5,     non_numeric6,        non_numeric_empty_string,
        max_int_overf, duplicate_sorted, duplicate_arguments, NULL
	};
    exec_each_void_param_function_in(test);
}

static void no_args() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap 2>&1");
    printf(CYAN "no_args ------------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, CMD_OUTPUT, !BONUS);
    system("rm -f error.log");
}

static void non_numeric1() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d %s 2>error.log", 3, 2, 1, "9a");
    printf(CYAN "non_numeric 1 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void non_numeric2() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d %s 2>error.log", 3, 2, 1, "a");
    printf(CYAN "non_numeric 2 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void non_numeric3() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d %s 2>error.log", 3, 2, 1, "12 a 2");
    printf(CYAN "non_numeric 3 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void non_numeric4() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d %s 2>error.log", 3, 2, 1, "12 - 2");
    printf(CYAN "non_numeric 4 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void non_numeric5() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d %s 2>error.log", 3, 2, 1, "12 --2");
    printf(CYAN "non_numeric 5 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void non_numeric6() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d %s 2>error.log", 3, 2, 1, "12 ++2");
    printf(CYAN "non_numeric 6 ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void non_numeric_empty_string() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap" " \"%s\" 2>error.log", "");
    printf(CYAN "empty_string -------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void max_int_overf() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d %lu 2>error.log",
            35, 24, 21, 21474836498);
    printf(CYAN "max_int_overf ------- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void duplicate_arguments() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d 2>error.log",
            1, 2, 1);
    printf(CYAN "duplicate_arguments - " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}

static void duplicate_sorted() {
	char cmd[CMD_LEN];
    sprintf(cmd, "valgrind --leak-check=full --show-leak-kinds=all" " -q ./push_swap %d %d %d %d %d %d 2>error.log",
            10, 11, 12, 13, 14, 14);
    printf(CYAN "duplicate_sorted ---- " DEF_COLOR);
    exec_test_and_analyse_output(cmd, LOG_FILE, !BONUS);
    system("rm -f error.log");
}
