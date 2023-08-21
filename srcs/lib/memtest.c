#include "averager.h"

void exec_memtest(int **table, char buffer[], char cmd[],
                  t_sizes_and_action sizes_and_action) {
    FILE *output;
    int arr_size = sizes_and_action.arr_size;
    int table_index = sizes_and_action.table_index;
    t_build_cmdstr *build_cmdstr = sizes_and_action.action;

    if (table_index != 1) {
        for (short three = 0; three < 3; three++) {
            build_cmdstr(cmd, table_index, table);
            output = popen(cmd, "r");
            fgets(buffer, 100, output);
            log_cmd_and_output(table, arr_size, table_index, buffer);
            fprintf_ok_ko(buffer, output, NULL);
            pclose(output);
            table_index++;
        }
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
