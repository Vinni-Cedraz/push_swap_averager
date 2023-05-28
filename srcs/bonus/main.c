#include "averager.h"

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table();
    dprintf(1, HRED
           "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "
           "FLAG\n\n" DEF_COLOR);
    // sleep(2);
    char cmd[5000];
	printf(HRED"\nrunning tests with valgrind -q\n"DEF_COLOR);
	printf(CYAN"no_args			-->	"DEF_COLOR);
 	no_args(cmd);
	printf(CYAN"empty string	 	-->	"DEF_COLOR);
    empty_string(cmd);
	printf(CYAN"non_numeric		-->	"DEF_COLOR);

 	non_numeric(cmd);
	printf(CYAN"max_int_overf		-->	"DEF_COLOR);

	max_int_overf(cmd);
	printf(CYAN"duplicate_sorted	-->	"DEF_COLOR);
    duplicate_sorted(cmd);
	printf(CYAN"invalid_action		-->	"DEF_COLOR);
	invalid_action(cmd);
	dprintf(1, CYAN"duplicate_args		-->	"DEF_COLOR);
 	duplicate_arg(cmd);
	printf(CYAN"whitespaced_action	-->	"DEF_COLOR);
	whitespaced_action(cmd);
    printf(WHITE "\n\nBONUS RIGHT TESTS" DEF_COLOR);
    printf(HRED"\n		with valgrind -q \n\n" DEF_COLOR);
    execute_bonus5(args);
    execute_bonus10(args);
    execute_bonus15(args);
    execute_bonus20(args);
    execute_bonus100(args);
    execute_bonus500(args);
    printf(CYAN
           "\n\n\nIf you didnt see any valgrind messages it means no "
           "memory leaks were found in your program\n\n\n\n" DEF_COLOR);
    ft_free_arr_size((void **)args->table, 100);
    free(args);
}
