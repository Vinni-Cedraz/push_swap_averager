#include "../include/averager.h"

void exec_memtest(int **table, t_sizes_and_action args) {
    FILE *output;
    char buffer[BUF_LEN];
    char cmd[HUGE_CMD_LEN];

    switch (args.table_index) {
    case 1:
        if (args.action == build_memtest3_string) {
            while (table[args.table_index]) {
                args.action(cmd, args.table_index, table);
                output = popen(cmd, "r");
                fgets(buffer, 100, output);
                log_cmd_and_output(table, 3, args.table_index, buffer);
                fprintf_ok_ko(buffer, output, NULL);
                pclose(output);
                args.table_index++;
            }
        } else if (args.action == build_test3_string) {
            while (table[args.table_index]) {
                args.action(cmd, args.table_index, table);
                output = popen(cmd, "r");
                fgets(buffer, 100, output);
                log_cmd_and_output_3(table, 3, args.table_index, buffer);
                pclose(output);
                args.table_index++;
            }
        }
        break;
    default:
        for (short three = 0; three < 3; three++) {
            args.action(cmd, args.table_index, table);
            output = popen(cmd, "r");
            fgets(buffer, 100, output);
            log_cmd_and_output(table, args.arr_size, args.table_index, buffer);
            fprintf_ok_ko(buffer, output, NULL);
            pclose(output);
            args.table_index++;
        }
    }
}
