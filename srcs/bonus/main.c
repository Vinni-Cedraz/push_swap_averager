#include "averager.h"

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table();
    printf(HRED
           "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "
           "FLAG\n\n\n" DEF_COLOR);
    sleep(3);
	FILE *fp;
    char *cmd = calloc(sizeof(char), 8000);
    char *output = calloc(sizeof(char), 8000);
	printf(HRED"\nrunning tests with valgrind -q\n"DEF_COLOR);
	printf("empty -->");
    empty_string(cmd, fp);
	printf("no_args -->");
    no_args(cmd, fp);
	printf("duplicate_args -->");
    duplicate_arg(cmd, fp);
	printf("duplicate_sorted -->");
    duplicate_sorted(cmd, fp);
	printf("non_numeric -->");
    non_numeric(cmd, fp);
	printf("max_int_overf -->");
	max_int_overf(cmd, fp);
	printf("invalid_action -->");
	invalid_action(cmd, fp);
	printf("whitespaced_action -->");
	whitespaced_action(cmd, fp);
    free(cmd);
    free(output);
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
