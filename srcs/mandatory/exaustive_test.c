#include "../include/averager.h"

static void exaustive_test20(t_args *args_void);
static void exaustive_test100(t_args *args_void);
static void exaustive20_footer(t_args this_task[8]);
static void exaustive100_footer(t_args this_task[8]);
static void init_this_task20(t_args *this_task, int **table, int task_size);
static void init_this_task100(t_args *this_task, int **table, int task_size);

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table_exaustive_tests();

    dprintf(1, EXAUSTIVE_TEST20_HEADER);
    exaustive_test20(args);
    exaustive_test100(args);
    ft_free_arr_size((void **)args->table, 1000);
    free(args);
}

static void exaustive_test20(t_args *args_void) {
    pthread_t pthread[8];
    static t_args this_task[8];
    for (int i = 0; i < 8; i++) {
        init_this_task20(&this_task[i], args_void->table, 20);
        pthread_create(&pthread[i], 0, execute_push_swap_thread, &this_task[i]);
    }
    for (int i = 0; i < 8; i++)
        pthread_join(pthread[i], NULL);
    create_unified_log_file20();
    exaustive20_footer(this_task);
}

static void init_this_task20(t_args *this_task, int **table, int task_size) {
    static int call_counter = -1;
    const int thread_idxs[8] = {0, 21, 41, 61, 81, 101, 121, 141};
    const char *tmp_files[] = {"tmp1", "tmp2", "tmp3", "tmp4",
                               "tmp5", "tmp6", "tmp7", "tmp8"};
    call_counter++;
    this_task->error = 0;
    this_task->table = table;
    this_task->size = task_size;
    this_task->tmp_file = tmp_files[call_counter];
    this_task->thread_idx = thread_idxs[call_counter];
    this_task->build_cmdstr = build_exaustive_checker_test_cmd_string;
    this_task->fprintf_result_to_file = fprintf_ok_ko;
}

static void exaustive20_footer(t_args this_task[8]) {
    bool error = 0;
    for (int i = 0; i < 8; i++) {
        error = this_task[i].error;
        if (error)
            break;
    }
    if (1 == error) {
        dprintf(1,
                RED "One or more sorting tests " HRED "FAILED!!!\n" YELLOW
                    "to see the details run: " DEF_COLOR
                    "cat push_swap_averager/log_files/exaustive20.log\n\n\n");
        exit(1);
    } else
        dprintf(1, GREEN
                "160 lists of 20 elements were sorted correctly\n" DEF_COLOR);
}

static void exaustive_test100(t_args *args_void) {
    pthread_t pthread[8];
    static t_args this_task[8];
    for (int i = 0; i < 8; i++) {
        init_this_task100(&this_task[i], args_void->table, 100);
        pthread_create(&pthread[i], 0, execute_push_swap_thread, &this_task[i]);
    }
    for (int i = 0; i < 8; i++)
        pthread_join(pthread[i], NULL);
    create_unified_log_file100();
    exaustive100_footer(this_task);
}

static void init_this_task100(t_args *this_task, int **table, int task_size) {
    static int call_counter = -1;
    const int thread_idxs[8] = {161, 181, 201, 221, 241, 261, 281, 301};
    const char *tmp_files[] = {"tmp1", "tmp2", "tmp3", "tmp4",
                               "tmp5", "tmp6", "tmp7", "tmp8"};
    call_counter++;
    this_task->error = 0;
    this_task->table = table;
    this_task->size = task_size;
    this_task->tmp_file = tmp_files[call_counter];
    this_task->thread_idx = thread_idxs[call_counter];
    this_task->build_cmdstr = build_exaustive_checker_test_cmd_string;
    this_task->fprintf_result_to_file = fprintf_ok_ko;
}

static void exaustive100_footer(t_args this_task[8]) {
    bool error = 0;
    for (int i = 0; i < 8; i++) {
        error = this_task[i].error;
        if (error)
            break;
    }
    if (1 == error) {
        dprintf(1,
                RED "One or more sorting tests " HRED "FAILED!!!\n" YELLOW
                    "to see the details run: " DEF_COLOR
                    "cat push_swap_averager/log_files/exaustive100.log\n\n\n");
        exit(1);
    } else
        dprintf(1, GREEN
                "160 lists of 100 elements were sorted correctly\n" DEF_COLOR);
}
