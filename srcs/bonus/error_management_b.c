#include <errno.h>

#include "averager.h"

#define EMPTY_EXPECTED 1
#define EMPTY_NOT_EXPECTED 0

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
            printf("Your checker: ");
            printf(HGREEN "OK\n" DEF_COLOR);
        } else
            bonus_log_error(EMPTY_EXPECTED, out_str);
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
                printf("Your checker: ");
                printf(HGREEN "OK\n" DEF_COLOR);
            } else
                bonus_log_error(EMPTY_NOT_EXPECTED, line);
        } else
            bonus_log_error(EMPTY_NOT_EXPECTED, line);
        fclose(error_log);
    }
    free(line);
}

void no_args(char *cmd) {
    sprintf(cmd, "(valgrind -q ./checker) 2>&1");
    get_test_output(cmd, 1);
}

void empty_string(char *cmd) {
    sprintf(cmd, "(valgrind -q ./checker %s) 2>&1", "");
    get_test_output(cmd, 1);
}

void non_numeric(char *cmd) {
    sprintf(cmd, "(valgrind -q ./checker %d %d %d %s) 2>error.log", 3, 2, 1,
            "9a");
    get_test_output(cmd, 0);
}

void max_int_overf(char *cmd) {
    sprintf(cmd, "(valgrind -q ./checker %d %d %d %lu) 2>error.log", 35, 24, 21,
            21474836498);
    get_test_output(cmd, 0);
}

void duplicate_sorted(char *cmd) {
    sprintf(cmd, "(valgrind -q ./checker %d %d %d %d %d %d) 2>error.log", 10,
            11, 12, 13, 14, 14);
    get_test_output(cmd, 0);
}

void duplicate_arg(char *cmd) {
    sprintf(cmd, "(valgrind -q ./checker %d %d %d) 2>error.log", 1, 2, 1);
    get_test_output(cmd, 0);
}

void invalid_action(char *cmd) {
    sprintf(cmd,
            "(cat cmds | valgrind -q ./checker %d %d %d %d %d %d) 2>error.log",
            11, 10, 12, 13, 14, 15);
    get_test_output(cmd, 0);
}

void whitespaced_action(char *cmd) {
    sprintf(cmd,
            "(cat cmds2 | valgrind -q ./checker %d %d %d %d %d %d) 2>error.log",
            11, 10, 12, 13, 14, 15);
    get_test_output(cmd, 0);
}
