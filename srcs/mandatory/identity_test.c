#include "../include/averager.h"

static void get_test_process_output(FILE *fp, char *output, char *test) {
    size_t bytes_read = fread(output, sizeof(char), 8000, fp);
    if (bytes_read) {
        printf(CYAN "%s------- " HRED "KO" DEF_COLOR, test);
		trim_linebreak(output);
        printf(RED
               "	Expected the string \"Error\\n\" on the stderr (fd "
               "2)");
        printf(BLUE "	Got" DEF_COLOR " \"" DEF_COLOR " \%s\"" BLUE
                    " instead" DEF_COLOR,
               output);
    } else
        printf(CYAN "%s------- " GREEN "OK" DEF_COLOR, test);
}

static void single_element(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "valgrind -q ./push_swap %d 2>&1", 42);
    fp = popen(cmd, "r");
    get_test_process_output(fp, output, "<sorted> single_element -");
    printf("	<--- %s\n", cmd);
    pclose(fp);
}

static void four_elements(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "valgrind -q ./push_swap %d %d %d %d 2>&1", 0, 1, 2, 3);
    fp = popen(cmd, "r");
    get_test_process_output(fp, output, "<sorted> four_elements  -");
    printf("	<--- %s\n", cmd);
    pclose(fp);
}

static void nine_elements(char *cmd, FILE *fp, char *output) {
    sprintf(cmd, "valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d 2>&1", 0,
            1, 2, 3, 4, 5, 6, 7, 8);
    fp = popen(cmd, "r");
    get_test_process_output(fp, output, "<sorted> nine_elements  -");
    printf("	<--- %s\n", cmd);
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
}
