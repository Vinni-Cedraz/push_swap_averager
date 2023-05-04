#include <assert.h>
#include <stdio.h>

#include "averager.h"

static void exec_test_process(char *cmd, FILE *fp, char *output, char *test) {
    size_t bytes_read = fread(output, sizeof(char), 8000, fp);
    if (!strncmp(test, "empty_string", 5) || !strncmp(test, "no_args", 5)) {
        if (bytes_read)
            printf(CYAN "%s----------- " HRED "Error\n" DEF_COLOR, test);
        else
            printf(CYAN "%s----------- " GREEN "OK\n" DEF_COLOR, test);
    } else {
        if (!strcmp(output, "Error\n"))
            printf(CYAN "%s----------- " GREEN "OK\n" DEF_COLOR, test);
        else
            printf(CYAN "%s----------- " HRED "Error\n" DEF_COLOR, test);
    }
}

static void empty_string(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./push_swap %s 2>&1", "");
    fp = popen(cmd, "r");
    exec_test_process(cmd, fp, output, "empty_string ----");
    pclose(fp);
}

static void no_args(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./push_swap 2>&1");
    fp = popen(cmd, "r");
    exec_test_process(cmd, fp, output, "no_args ---------");
    pclose(fp);
}

static void duplicate_arg(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./push_swap %d %d %d 2>&1", 1, 2, 1);
    fp = popen(cmd, "r");
    exec_test_process(cmd, fp, output, "duplicate_arg ---");
    pclose(fp);
}

static void duplicate_sorted(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./push_swap %d %d %d %d %d %d 2>&1", 10, 11, 12, 13, 14, 14);
    fp = popen(cmd, "r");
    exec_test_process(cmd, fp, output, "duplicate_sorted ");
    pclose(fp);
}

static void non_numeric(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./push_swap %d %d %d %s 2>&1", 3, 2, 1, "9a");
    fp = popen(cmd, "r");
    exec_test_process(cmd, fp, output, "non_numeric -----");
    pclose(fp);
}

static void max_int_overf(char *cmd, FILE *fp, char *output) {
	sprintf(cmd, "./push_swap %d %d %d %lu 2>&1", 35, 24, 21, 21474836498);
	fp = popen(cmd, "r");
	exec_test_process(cmd, fp, output, "max_int_overflow ");
    pclose(fp);
}

int main(void) {
    char *cmd;
    FILE *fp;
    char *output;

    cmd = calloc(sizeof(char), 8000);
    output = calloc(sizeof(char), 8000);
    empty_string(cmd, fp, output);
    no_args(cmd, fp, output);
    duplicate_arg(cmd, fp, output);
    duplicate_sorted(cmd, fp, output);
    non_numeric(cmd, fp, output);
	max_int_overf(cmd, fp, output);
    free(cmd);
    free(output);
    printf(WHITE "\nERROR MANAGEMENT: " GREEN "OK\n\n" DEF_COLOR);
}
