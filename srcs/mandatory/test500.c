#include "averager.h"

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

int main(void) {
    t_uargs *this_task = malloc(sizeof(t_uargs) * 8);
    pthread_t pthread[8];
    const int thread_idxs[] = {0, 61, 121, 181, 241, 301, 361, 421};
    const char *tmp_files[] = {"tmp1", "tmp2", "tmp3", "tmp4",
                               "tmp5", "tmp6", "tmp7", "tmp8"};
	int **table = init_permutation_table();

    printf(WHITE "\nTESTS FOR SIZE 500\n" DEF_COLOR);
    for (int i = 0; i < 8; i++) {
        this_task[i].table = table;
        this_task[i].tmp_file = tmp_files[i];
        this_task[i].thread_idx = thread_idxs[i];
		this_task[i].size = 500;
        pthread_create(&pthread[i], NULL, execute_push_swap_thread, &this_task[i]);
    }

    for (int i = 0; i < 8; i++)
        pthread_join(pthread[i], NULL);
    ft_free_arr_size((void **)this_task->table, 481);
    free(this_task);
}
