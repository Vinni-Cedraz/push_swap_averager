#include "../include/averager.h"

static void log_bonus_tests_header(void);
static void log_bonus_tests_footer(void);
static t_args *args_for_execute_bonus(t_args*);

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table_memtests_sizes();
    static void (*error_management[])(char *) = {
		no_args, non_numeric_empty_string, non_numeric1, non_numeric2, non_numeric3,
		non_numeric4, non_numeric5, non_numeric6, max_int_overf, duplicate_sorted,
		b_invalid_action, duplicate_arguments, b_whitespaced_action, NULL
	};
    log_bonus_tests_header();
    exec_each_function_in(error_management, "./checker");
	for (int idx = 0; idx < 6; idx++) execute_bonus(args_for_execute_bonus(args));
    log_bonus_tests_footer();
    ft_free_arr_size((void **)args->table, 100);
    free(args);
}

static inline t_args *args_for_execute_bonus(t_args *args) {
	static int call_counter = -1;
 	const static t_action action[] = {
     	(t_action){.arr_size =   5, .tab_idx =  7},
     	(t_action){.arr_size =  10, .tab_idx = 11},
	 	(t_action){.arr_size =  15, .tab_idx = 15},
     	(t_action){.arr_size =  20, .tab_idx = 19},
     	(t_action){.arr_size = 100, .tab_idx = 23},
     	(t_action){.arr_size = 500, .tab_idx = 27}
	};
	args->sizes_and_idx = action[++call_counter];
	return args;
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
