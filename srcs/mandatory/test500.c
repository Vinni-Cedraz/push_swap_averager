#include "../include/averager.h"

static uint **init_permutation_table(void) {
    int count = 0;
    uint *tmp_arr = malloc(sizeof(uint *) * 500);
    uint **table = calloc(sizeof(uint *), 481);
    for (int i = 0; i < 500; i++)
        tmp_arr[i] = i;
    srand(time(NULL) ^ (getpid() << 16));
    shuffle_array(tmp_arr, 500, rand());

    while (count < 480) {
        if (count && (count % 60) == 0)
            table[count] = NULL;
        else if (!is_repeated500(table, tmp_arr, count)) {
            table[count] = calloc(sizeof(uint), 500);
            memcpy(table[count], tmp_arr, 500 * sizeof(uint));
        }
        shuffle_array(tmp_arr, 500, rand());
        count++;
    }

    free(tmp_arr);
    return table;
}

static void init_this_task(t_uargs *this_task, int **table, int task_size) {
    static int call_counter = -1;
    static const int thread_idxs[] = {0, 61, 121, 181, 241, 301, 361, 421};
    static const char *tmp_files[] = {"tmp1", "tmp2", "tmp3", "tmp4",
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
    static t_uargs this_task[8];
    pthread_t pthread[8];
    int **table = init_permutation_table();

    printf(WHITE "\nTESTS FOR SIZE 500\n" DEF_COLOR);
    for (int i = 0; i < 8; i++) {
        init_this_task(&this_task[i], table, 500);
        pthread_create(&pthread[i], NULL, execute_push_swap_thread, &this_task[i]);
    }

    for (int i = 0; i < 8; i++)
        pthread_join(pthread[i], NULL);
    ft_free_arr_size((void **)this_task->table, 481);
}
