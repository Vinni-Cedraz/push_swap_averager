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
    empty_string(cmd, fp, output);
    no_args(cmd, fp, output);
    duplicate_arg(cmd, fp, output);
    duplicate_sorted(cmd, fp, output);
    non_numeric(cmd, fp, output);
	max_int_overf(cmd, fp, output);
	printf(HRED"\nATTENTION:	in the following two tests I'll check if"
			" your program outputs the string \"Error\\n\" as it's last output.\n\n");
	sleep(3);
	printf(
			CYAN"I do this because that's what the official checker does.\n"
			CYAN"However, during evaluation, the ruler can be more forgiving if you print \"Error\\n\" in a different order\n\n"DEF_COLOR);
	sleep(3);
	invalid_action(cmd, fp, output);
	whitespaced_action(cmd, fp, output);
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
