#include "../include/averager.h"

void exec_memtest(int **table, t_sizes_and_action args) {
    FILE *output;
    char buffer[BUF_LEN];
    char cmd[HUGE_CMD_LEN];

    switch (args.tab_idx) {
    case 1: // case tabls_index is 1 means the array has 3 numbers
        if (args.action == build_memtest_cmdstring) {
            while (table[args.tab_idx]) {
                args.action(cmd, args.arr_size, args.tab_idx, table);
                output = popen(cmd, "r");
                fgets(buffer, 100, output);
                log_cmd_and_output(table, args.arr_size, args.tab_idx, buffer);
                fprintf_ok_ko(buffer, output, NULL);
                pclose(output);
                args.tab_idx++;
            }
        } else if (args.action == build_three_elements_memtest_cmdstring) {
            while (table[args.tab_idx]) {
                args.action(cmd, args.arr_size, args.tab_idx, table);
                output = popen(cmd, "r");
                fgets(buffer, 100, output);
                log_cmd_and_output_3(table, args.arr_size, args.tab_idx,
                                     buffer);
                pclose(output);
                args.tab_idx++;
            }
        }
        break;
    default:
        for (short three = 0; three < 3; three++) {
            args.action(cmd, args.arr_size, args.tab_idx, table);
            output = popen(cmd, "r");
            fgets(buffer, 100, output);
            log_cmd_and_output(table, args.arr_size, args.tab_idx, buffer);
            fprintf_ok_ko(buffer, output, NULL);
            pclose(output);
            args.tab_idx++;
        }
    }
}
