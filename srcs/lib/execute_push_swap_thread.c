#include "../include/averager.h"

void *execute_push_swap_thread(void *arg) {
    t_uargs *this_task = (t_uargs *)arg;
    char cmd[BIG_CMD_LEN];
    char buffer[BUF_LEN];
    FILE *output;

    int idx = this_task->thread_idx;
    FILE *fp = fopen(this_task->tmp_file, "a");
    while (this_task->table[idx]) {
        this_task->build_cmd_string(cmd, this_task->size, idx, this_task->table);
        execute_cmd(cmd, buffer, output);
        print_array_to_file(fp, idx, this_task->size, this_task->table);
        this_task->fprintf_result_to_file(buffer, fp, &this_task->error);
        handle_err(this_task->table, this_task->size, idx, buffer);
        idx++;
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}
