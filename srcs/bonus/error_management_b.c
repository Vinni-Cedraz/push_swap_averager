#include "averager.h"

static void get_test_output(char *cmd, FILE *fp, char *output, char *test) {
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

void empty_string(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./checker %s 2>&1", "");
    fp = popen(cmd, "r");
    get_test_output(cmd, fp, output, "empty_string ------");
    pclose(fp);
}

void no_args(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./checker 2>&1");
    fp = popen(cmd, "r");
    get_test_output(cmd, fp, output, "no_args -----------");
    pclose(fp);
}

void duplicate_arg(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./checker %d %d %d 2>&1", 1, 2, 1);
    fp = popen(cmd, "r");
    get_test_output(cmd, fp, output, "duplicate_arg -----");
    pclose(fp);
}

void duplicate_sorted(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./checker %d %d %d %d %d %d 2>&1", 10, 11, 12, 13, 14, 14);
    fp = popen(cmd, "r");
    get_test_output(cmd, fp, output, "duplicate_sorted --");
    pclose(fp);
}

void non_numeric(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "./checker %d %d %d %s 2>&1", 3, 2, 1, "9a");
    fp = popen(cmd, "r");
    get_test_output(cmd, fp, output, "non_numeric -------");
    pclose(fp);
}

void max_int_overf(char *cmd, FILE *fp, char *output) {
	sprintf(cmd, "./checker %d %d %d %lu 2>&1", 35, 24, 21, 21474836498);
	fp = popen(cmd, "r");
	get_test_output(cmd, fp, output, "max_int_overflow --");
    pclose(fp);
}

void invalid_action(char *cmd, FILE *fp, char *output) {
	sprintf(cmd, "cat cmds | ./checker %d %d %d %d %d %d 2>&1", 11, 10, 12, 13, 14, 15);
	fp = popen(cmd, "r");
	get_test_output(cmd, fp, output, "invalid_action ----");
	pclose(fp);
}

void whitespaced_action(char *cmd, FILE *fp, char *output) {
	sprintf(cmd, "cat cmds2 | ./checker %d %d %d %d %d %d 2>&1", 11, 10, 12, 13, 14, 15);
	fp = popen(cmd, "r");
	get_test_output(cmd, fp, output, "whitespaced_action ");
	pclose(fp);
}
