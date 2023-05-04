#include <assert.h>
#include <stdio.h>

#include "averager.h"

static void empty_string(char cmd[], FILE *fp, char *output) {
    sprintf(cmd, "./push_swap %s", "");
    fp = popen(cmd, "r");
    output = fgets(cmd, 8000, fp);
    printf("%s \"\"\n", cmd);
    if (output != NULL)
        printf(HRED "Error\n" DEF_COLOR);
    else
        printf(CYAN "empty arg: " GREEN "OK\n" DEF_COLOR);
    pclose(fp);
}

static void no_args(char cmd[], FILE *fp, char *output) {
	sprintf(cmd, "./push_swap");
	fp = popen(cmd, "r");
	output = fgets(cmd, 8000, fp);
	printf("%s\n", cmd);
	if (output != NULL)
		printf(HRED "Error\n" DEF_COLOR);
	else
		printf(CYAN "  no args: " GREEN "OK\n" DEF_COLOR);
    pclose(fp);
}

int main(void) {
    char cmd[8000];
    FILE *fp;
    char *output;

	empty_string(cmd, fp, output);
	no_args(cmd, fp, output);
}
