#include "averager.h"

static void execute_memtests(void *args_void);
static void log_memtests_header(void);
static t_sizes_and_action get_sizes_and_action(void);

int main(void) {
    t_args *args;

    args = malloc(sizeof(t_args));
    args->table = init_table();
    execute_memtests(args);
    exaustive_test20(args);
    ft_free_arr_size((void **)args->table, 1000);
    free(args);
}

static void execute_memtests(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;

    log_memtests_header();

	for (int exec_eight_times = 0; exec_eight_times < 8; exec_eight_times++)
    	exec_memtest(table, get_sizes_and_action());
    dprintf(1, MEMORY_TEST_FOOTER);
}

static t_sizes_and_action get_sizes_and_action(void) {
    static short call_counter;
    const static t_sizes_and_action sizes_and_action[9] = {
        {.arr_size =  -1, .table_index = -1, .action = NULL},
        {.arr_size =   3, .table_index =  1, .action = &build_memtest3_string},
        {.arr_size =   3, .table_index =  1, .action = &build_test3_string},
        {.arr_size =   5, .table_index =  7, .action = &build_memtest5_string},
        {.arr_size =  10, .table_index = 11, .action = &build_memtest10_string},
        {.arr_size =  15, .table_index = 15, .action = &build_memtest15_string},
        {.arr_size =  20, .table_index = 19, .action = &build_memtest20_string},
        {.arr_size = 100, .table_index = 23, .action = &build_memtest100_string},
        {.arr_size = 500, .table_index = 27, .action = &build_memtest500_string},
    };
	return (sizes_and_action[++call_counter]);
}

static void log_memtests_header(void) {
    dprintf(1, MEMORY_TEST_HEADER);
    sleep(3);
    dprintf(STDOUT_FILENO, MEMORY_TEST_MESSAGE);
}
