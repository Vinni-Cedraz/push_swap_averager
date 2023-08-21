#include "averager.h"

static void execute_memtests(void *args_void);
static void log_memtests_header(void);
static int arr_size(void);
static int table_index(void);
static t_build_cmdstr *test_string(void);

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
    char buf[100];
    char cmd[10000];

    log_memtests_header();
    for (int i = 0; i < 8; i++)
        exec_memtest(table, arr_size(), table_index(), buf, cmd, test_string());
    dprintf(1, MEMORY_TEST_FOOTER);
}

static int arr_size(void) {
    const static int arr_sizes[9] = {-1, 3, 3, 5, 10, 15, 20, 100, 500};
    static short call_counter;
    return arr_sizes[++call_counter];
}

static int table_index(void) {
    const static int arr_sizes[9] = {-1, 1, 1, 7, 11, 15, 19, 23, 27};
    static short call_counter;
    return arr_sizes[++call_counter];
}

static t_build_cmdstr *test_string(void) {
    static short call_counter;
    const static t_build_cmdstr *arr_sizes[9] = {
        NULL,
        &build_memtest3_string,
        &build_test3_string,
        &build_memtest5_string,
        &build_memtest10_string,
        &build_memtest15_string,
        &build_memtest20_string,
        &build_memtest100_string,
        &build_memtest500_string,
    };
    return arr_sizes[++call_counter];
}

static void log_memtests_header(void) {
    dprintf(1, MEMORY_TEST_HEADER);
    sleep(3);
    dprintf(STDOUT_FILENO, MEMORY_TEST_MESSAGE);
}
