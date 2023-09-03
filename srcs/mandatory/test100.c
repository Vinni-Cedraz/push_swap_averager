#include "../include/averager.h"

static uint **init_permutation_table(void) {
    int count = 0;
    int j = 1;
    uint *tmp_arr;
    uint **table = calloc(sizeof(uint *), 1300);
    srand(time(NULL) ^ (getpid() << 16));

    for (int i = 1; i <= 100; i++) {
        tmp_arr = seq_except(i);
        for (int k = 1; k <= 12; k++) {
            if (count && (count % 143) == 0) {
                if (count >= 1300)
                    break;
                table[count] = NULL;
                count++;
            }
            if (count >= 1300)
                break;
            table[count] = calloc(sizeof(uint), 100);
            table[count][0] = i;
            shuffle_array(tmp_arr, 99, rand());
            if (is_repeated100(table, tmp_arr, count)) {
                k--;
                free(table[count]);
                continue;
            }
            int k = 0;
            for (j = 1; j < 100; j++) {
                table[count][j] = tmp_arr[k];
                k++;
            }
            count++;
        }
        free(tmp_arr);
    }
    return table;
}

static void init_this_task(t_uargs *this_task, int **table, int task_size) {
    static int call_counter = -1;
    const int thread_idxs[8] = {0, 144, 288, 432, 576, 732, 888, 1044};
    const char *tmp_files[] = {"tmp1", "tmp2", "tmp3", "tmp4",
                               "tmp5", "tmp6", "tmp7", "tmp8"};
    call_counter++;
    this_task->table = table;
    this_task->size = task_size;
    this_task->tmp_file = tmp_files[call_counter];
    this_task->thread_idx = thread_idxs[call_counter];
	this_task->build_cmd_string = build_averager_test_cmd_string;
	this_task->fprintf_result_to_file = fprintf_nb_of_op;
}

int main(void) {
    pthread_t pthread[8];
    static t_uargs this_task[8];
    uint **table = init_permutation_table();
    printf(WHITE "\nTESTS FOR SIZE 100\n" DEF_COLOR);

    for (int i = 0; i < 8; i++) {
        init_this_task(&this_task[i], table, 100);
        pthread_create(&pthread[i], NULL, execute_push_swap_thread, &this_task[i]);
    }

    for (int i = 0; i < 8; i++)
        pthread_join(pthread[i], NULL);
    ft_free_arr((char **)this_task->table, (void **)this_task->table);
}
