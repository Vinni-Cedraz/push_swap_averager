#include "../include/averager.h"

static void process_operations_test_output(FILE *output, int **table, t_action action, char *buffer);
static void process_sorting_test_output(FILE *output, int **table, t_action action, char *buffer);

void exec_memtest(int **table, t_action action) {
    char buffer[BUF_LEN];
    char cmd[HUGE_CMD_LEN];
    static void (*process_test_output[])(FILE *, int **, t_action, char *) = {
        process_sorting_test_output,
        process_operations_test_output,
    };
    while (table[action.tab_idx]) {
        action.build_cmd(cmd, action.arr_size, action.tab_idx, table);
        FILE *output = popen(cmd, "r");
        fgets(buffer, 100, output);
        process_test_output[action.is_sorting_test](output, table, action, buffer);
        pclose(output);
        action.tab_idx++;
    }
}

static inline void process_operations_test_output(FILE *output, int **table, t_action action, char *buffer) {
    log_cmd_and_output_3(table, action.arr_size, action.tab_idx, buffer);
}

static inline void process_sorting_test_output(FILE *output, int **table, t_action action, char *buffer) {
    log_cmd_and_output(table, action.arr_size, action.tab_idx, buffer);
    fprintf_ok_ko(buffer, output, NULL);
}
