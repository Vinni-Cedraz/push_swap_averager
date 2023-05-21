#include "../include/averager.h"

void execute_memtest(int **table, int size, int i, char buffer[],
                     char cmd[], t_build_cmdstr build_cmdstr) {
	build_cmdstr(cmd, i, table);
    FILE *output = popen(cmd, "r");
    fgets(buffer, 100, output);
    log_cmd_and_output(table, size, i, buffer);
    fprintf_ok_ko(buffer, output, NULL);
    pclose(output);
}
