#include "../include/averager.h"

// static inline void exec_memtest_aux(int **table, t_sizes_and_action action);

void exec_memtest(int **table, t_sizes_and_action action) {
    FILE *output;
    char buffer[BUF_LEN];
    char cmd[HUGE_CMD_LEN];

    switch (action.build_cmd == build_three_elements_memtest_cmdstring) {
    case TRUE:
        while (table[action.tab_idx]) {
            action.build_cmd(cmd, action.arr_size, action.tab_idx, table);
            output = popen(cmd, "r");
            fgets(buffer, 100, output);
            log_cmd_and_output_3(table, action.arr_size, action.tab_idx, buffer);
            pclose(output);
            action.tab_idx++;
        }
    default:
        while (table[action.tab_idx]) {
            action.build_cmd(cmd, action.arr_size, action.tab_idx, table);
            output = popen(cmd, "r");
            fgets(buffer, 100, output);
            log_cmd_and_output(table, action.arr_size, action.tab_idx, buffer);
            fprintf_ok_ko(buffer, output, NULL);
            pclose(output);
            action.tab_idx++;
        }
    }
}
