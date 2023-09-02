
#include "averager.h"

void *execute_push_swap_thread(void *arg) {
    char command[BIG_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    t_uargs *this_task = (t_uargs *)arg;
	int arr_size = this_task->size;
    uint **table = this_task->table;
    int idx = this_task->thread_idx;
    fp = fopen(this_task->tmp_file, "a");
    while (table[idx]) {
        build_averager_test_cmd_string(command, arr_size, idx, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, BLUE "arr[%d]:" DEF_COLOR, idx);
        fprintf(fp, " ./push_swap ");
        for (int j = 0; j < arr_size; j++)
            fprintf(fp, "%d ", table[idx][j]);
        fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
        handle_err(table, arr_size, idx, out_str);
        pclose(output);
        idx++;
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}
