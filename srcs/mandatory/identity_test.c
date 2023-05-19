#include "../include/averager.h"

static void get_test_process_output(FILE *fp, char *output, char *test) {
    size_t bytes_read = fread(output, sizeof(char), 8000, fp);
    if (bytes_read)
        printf(CYAN "%s------- " HRED "Error\n" DEF_COLOR, test);
    else
        printf(CYAN "%s------- " GREEN "OK\n" DEF_COLOR, test);
}

static void single_element(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "valgrind -q ./push_swap %d 2>&1", 42);
    fp = popen(cmd, "r");
    get_test_process_output(fp, output, "<sorted> single_element -");
    pclose(fp);
}

static void four_elements(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "valgrind -q ./push_swap %d %d %d %d 2>&1", 0, 1, 2, 3);
    fp = popen(cmd, "r");
    get_test_process_output(fp, output, "<sorted> four_elements --");
    pclose(fp);
}

static void nine_elements(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d 2>&1", 0, 1, 2, 3, 4,
            5, 6, 7, 8);
    fp = popen(cmd, "r");
    get_test_process_output(fp, output, "<sorted> nine_elements --");
    pclose(fp);
}

int main(void) {
    char *cmd;
    FILE *fp;
    char *output;

	fp = NULL;
    cmd = calloc(sizeof(char), 8000);
    output = calloc(sizeof(char), 8000);
	single_element(cmd, fp, output);
	four_elements(cmd, fp, output);
	nine_elements(cmd, fp, output);
    free(cmd);
    free(output);
    printf(WHITE "\nIDENTITY TEST: " GREEN "OK\n\n" DEF_COLOR);
}
