#include "../include/averager.h"

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table_memtests_sizes();
    dprintf(1, HRED
           "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "
           "FLAG\n\n" DEF_COLOR);
    sleep(2);
    char cmd[5000];
	printf(HRED"\nrunning tests with valgrind on quiet mode (-q flag)\n"DEF_COLOR);
	printf(CYAN"no_args      "DEF_COLOR"cmd -> ./checker              ");
 	b_no_args(cmd);
	printf(CYAN"empty string "DEF_COLOR"cmd -> ./checker \"\"           ");
    b_empty_string(cmd);
	printf(CYAN"non_numeric  "DEF_COLOR"cmd -> ./checker 3 2 1 9a     ");
 	b_non_numeric1(cmd);
	printf(CYAN"non_numeric  "DEF_COLOR"cmd -> ./checker 3 2 1 a      ");
 	b_non_numeric2(cmd);
	printf(CYAN"non_numeric  "DEF_COLOR"cmd -> ./checker 3 2 1 12 a 2 ");
 	b_non_numeric3(cmd);
	printf(CYAN"non_numeric  "DEF_COLOR"cmd -> ./checker 3 2 1 12 - 2 ");
 	b_non_numeric4(cmd);
	printf(CYAN"non_numeric  "DEF_COLOR"cmd -> ./checker 3 2 1 12 --2 ");
 	b_non_numeric5(cmd);
	printf(CYAN"non_numeric  "DEF_COLOR"cmd -> ./checker 3 2 1 12 ++2 ");
 	b_non_numeric6(cmd);
	printf("====================================================================================\n");
	printf(CYAN"max_int_overf"DEF_COLOR"      cmd -> ./checker 35 24 21 21474836498               ");
	b_max_int_overf(cmd);
	printf(CYAN"duplicate_sorted"DEF_COLOR"   cmd -> ./checker 10, 11, 12, 13, 14, 14             ");
    b_duplicate_sorted(cmd);
	printf(CYAN"invalid_action"DEF_COLOR"     cmd -> cat cmds | ./checker 11, 10, 12, 13, 14, 15  ");
	b_invalid_action(cmd);
	dprintf(1, CYAN"duplicate_args"DEF_COLOR"     cmd -> ./checker 1 2 1                              ");
 	b_duplicate_arg(cmd);
	printf(CYAN"whitespaced_action"DEF_COLOR" cmd -> cat cmds2 | ./checker 11, 10, 12, 13, 14, 15 ");
	b_whitespaced_action(cmd);
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
