#include "../include/averager.h"



static void log_bonus_tests_header(void);
static void log_bonus_tests_footer(void);



int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table_memtests_sizes();
    static void (*sorting_and_memory[])(void *) = {
        execute_bonus5, execute_bonus10, execute_bonus15, execute_bonus20,
		execute_bonus100, execute_bonus500, NULL
	};
    static void (*error_management[])(char *) = {
		no_args, non_numeric_empty_string, non_numeric1, non_numeric2, non_numeric3,
		non_numeric4, non_numeric5, non_numeric6, max_int_overf, duplicate_sorted,
		b_invalid_action, duplicate_arguments, b_whitespaced_action, NULL
	};
    log_bonus_tests_header();
    exec_each_function_in(error_management, "./checker");
    bonus_exec_each_function_in(sorting_and_memory, args);
    log_bonus_tests_footer();
    ft_free_arr_size((void **)args->table, 100);
    free(args);
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
