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
    empty_string(cmd, fp, output);
    no_args(cmd, fp, output);
    duplicate_arg(cmd, fp, output);
    duplicate_sorted(cmd, fp, output);
    non_numeric(cmd, fp, output);
	max_int_overf(cmd, fp, output);
	invalid_action(cmd, fp, output);
	whitespaced_action(cmd, fp, output);
    free(cmd);
    free(output);
    printf(WHITE "\n       BONUS ERROR MANAGEMENT: " GREEN "OK\n" DEF_COLOR);
    printf(WHITE "\n\n\n\n\nBONUS RIGHT TESTS" DEF_COLOR);
    printf(HRED"\n		with valgrind -q \n\n" DEF_COLOR);
    execute_bonus5(args);
    execute_bonus10(args);
    execute_bonus15(args);
    execute_bonus20(args);
    execute_bonus100(args);
    execute_bonus500(args);
    execute_bonus1000(args);
    ft_free_arr_size((void **)args->table, 100);
    free(args);
    printf(CYAN
           "\n\n\nIf you didnt see any valgrind messages it means no "
           "memory leaks were found in your program\n\n\n\n" DEF_COLOR);
}
