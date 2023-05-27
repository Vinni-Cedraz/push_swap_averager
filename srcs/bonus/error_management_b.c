#include "averager.h"

static void get_test_output(FILE *fp, char *cmd, bool empty_expected) {
    fp = popen(cmd, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (empty_expected) {
        char *out_str;
        fread(out_str, 1, 100, fp);
        if (NULL != out_str) {
            printf("Your checker: ");
            printf(HRED "KO\n" DEF_COLOR);
            printf(RED
                   "	Expected nothing either on stderr nor on stdout (fd "
                   "1)\n" DEF_COLOR);
        } else {
            printf("Your checker: ");
            printf(HGREEN "OK\n" DEF_COLOR);
        }
        pclose(fp);
        return;
    }
    FILE *error_log = fopen("error.log", "r");
    if ((read = getline(&line, &len, error_log)) != -1) {
        if (strcmp(line, "Error\n") == 0) {
            printf("Your checker: ");
            printf(HGREEN "OK\n" DEF_COLOR);
        } else if (!empty_expected) {
            printf(HRED "KO\n" DEF_COLOR);
            printf(RED
                   "	Expected the string \"Error\\n\" on the stderr (fd "
                   "2)\n" DEF_COLOR);
        }
    }
    fclose(error_log);
    pclose(fp);
}

void empty_string(char *cmd, FILE *fp) {
    sprintf(cmd, "(valgrind -q ./checker %s) 2>error.log", "");
    get_test_output(fp, cmd, 1);
}

void no_args(char *cmd, FILE *fp) {
    sprintf(cmd, "(valgrind -q ./checker) 2>error.log");
    get_test_output(fp, cmd, 1);
}

void duplicate_arg(char *cmd, FILE *fp) {
    sprintf(cmd, "(valgrind -q ./checker %d %d %d) 2>error.log", 1, 2, 1);
    get_test_output(fp, cmd, 0);
}

void duplicate_sorted(char *cmd, FILE *fp) {
    sprintf(cmd, "(valgrind -q ./checker %d %d %d %d %d %d) 2>error.log", 10,
            11, 12, 13, 14, 14);
    get_test_output(fp, cmd, 0);
}

void non_numeric(char *cmd, FILE *fp) {
    sprintf(cmd, "(valgrind -q ./checker %d %d %d %s) 2>error.log", 3, 2, 1,
            "9a");
    get_test_output(fp, cmd, 0);
}

void max_int_overf(char *cmd, FILE *fp) {
    sprintf(cmd, "(valgrind -q ./checker %d %d %d %lu) 2>error.log", 35, 24, 21,
            21474836498);
    get_test_output(fp, cmd, 0);
}

void invalid_action(char *cmd, FILE *fp) {
    sprintf(cmd,
            "(cat cmds | valgrind -q ./checker %d %d %d %d %d %d) 2>error.log",
            11, 10, 12, 13, 14, 15);
    get_test_output(fp, cmd, 0);
}

void whitespaced_action(char *cmd, FILE *fp) {
    sprintf(cmd,
            "(cat cmds2 | valgrind -q ./checker %d %d %d %d %d %d) 2>error.log",
            11, 10, 12, 13, 14, 15);
    get_test_output(fp, cmd, 0);
}
