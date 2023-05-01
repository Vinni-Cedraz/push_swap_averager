#include "averager.h"

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table();
    printf(HRED
           "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "
           "FLAG\n\n\n" DEF_COLOR);
    sleep(5);
    printf(WHITE "BONUS BASIC TESTS" DEF_COLOR);
    printf(CYAN "	with valgrind -q \n\n\n" DEF_COLOR);
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
