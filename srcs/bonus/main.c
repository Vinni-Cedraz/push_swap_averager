#include "../include/averager.h"

static void log_bonus_tests_header(void);
static void log_bonus_tests_footer(void);

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table_memtests_sizes();
    static void (*error_management[])() = {
        b_no_args,        b_empty_string,  b_non_numeric1,       b_non_numeric2,  b_non_numeric3,
        b_non_numeric4,   b_non_numeric5,  b_non_numeric6,       b_max_int_overf, b_duplicate_sorted,
        b_invalid_action, b_duplicate_arg, b_whitespaced_action, NULL
    };
    static void (*sorting_and_memory[])(void *) = {
        execute_bonus5, execute_bonus10, execute_bonus15, execute_bonus20, execute_bonus100, execute_bonus500, NULL
	};
    log_bonus_tests_header();
    exec_each_void_param_function_in(error_management);
    exec_each_t_args_param_function_in(sorting_and_memory, args);
    ft_free_arr_size((void **)args->table, 100);
    free(args);
    log_bonus_tests_footer();
}

static void log_bonus_tests_header(void) {
    dprintf(1, HRED "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 FLAG\n\n" DEF_COLOR);
    sleep(2);
    printf(HRED "\nrunning tests with valgrind on quiet mode (-q flag)\n" DEF_COLOR);
}

static void log_bonus_tests_footer(void) {
    printf("\n\n\n");
    printf(CYAN "If you didnt see any valgrind messages it means no memory leaks were found in your program" DEF_COLOR);
    printf("\n\n\n\n");
}
