#include "../include/averager.h"

void execute_memtest(int **table, int size, int table_index, char buffer[],
                     char cmd[], t_build_cmdstr build_cmdstr) {
    FILE *output;

    if (table_index != 1) {
        build_cmdstr(cmd, table_index, table);
        output = popen(cmd, "r");
        fgets(buffer, 100, output);
        log_cmd_and_output(table, size, table_index, buffer);
        fprintf_ok_ko(buffer, output, NULL);
        pclose(output);
    } else if (build_cmdstr == build_memtest3_string) {
        while (table[table_index]) {
            build_cmdstr(cmd, table_index, table);
            output = popen(cmd, "r");
            fgets(buffer, 100, output);
            log_cmd_and_output(table, 3, table_index, buffer);
            fprintf_ok_ko(buffer, output, NULL);
            pclose(output);
            table_index++;
        }
    } else if (build_cmdstr == build_test3_string) {
        while (table[table_index]) {
            build_cmdstr(cmd, table_index, table);
            output = popen(cmd, "r");
            fgets(buffer, 100, output);
            log_cmd_and_output_3(table, 3, table_index, buffer);
            pclose(output);
            table_index++;
        }
    }
}
