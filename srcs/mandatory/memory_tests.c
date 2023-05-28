#include "../include/averager.h"

static void execute_memtests(void *args_void);
static void log_memtests_header(void);
static void log_exaustive_test20_header(void);
static void log_memtests_footer(void);
static void log_exaustive_test20_footer(void);
static int size(void);

int main(void) {
    t_args *args;

    args = malloc(sizeof(t_args));
    args->table = init_table();
    log_memtests_header();
    execute_memtests(args);
    log_memtests_footer();
    log_exaustive_test20_header();
    exaustive_test20(args);
    log_exaustive_test20_footer();
    ft_free_arr_size((void **)args->table, 1000);
    free(args);
}

static void execute_memtests(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char buffer[100];
    char cmd[10000];

    dprintf(1, WHITE "\nMEMORY AND SORTING TESTS\n" DEF_COLOR CYAN
                     "	with valgrind on quiet mode (-q flag) \n\n\n" DEF_COLOR);
    execute_memtest(table, size(), 01, buffer, cmd, build_memtest3_string);
    execute_memtest(table, size(), 01, buffer, cmd, build_test3_string);
    execute_memtest(table, size(), 07, buffer, cmd, build_memtest5_string);
    execute_memtest(table, size(), 11, buffer, cmd, build_memtest10_string);
    execute_memtest(table, size(), 15, buffer, cmd, build_memtest15_string);
    execute_memtest(table, size(), 19, buffer, cmd, build_memtest20_string);
    execute_memtest(table, size(), 23, buffer, cmd, build_memtest100_string);
    execute_memtest(table, size(), 27, buffer, cmd, build_memtest500_string);
}

static int size(void) {
    static short call_counter;
    call_counter++;
    if (1 == call_counter) return 3;
    if (2 == call_counter) return 3;
    if (3 == call_counter) return 5;
    if (4 == call_counter) return 10;
    if (5 == call_counter) return 15;
    if (6 == call_counter) return 20;
    if (7 == call_counter) return 100;
    if (8 == call_counter) return 500;
}

static void log_memtests_header(void) {
    dprintf(1, HRED
            "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "
            "FLAG\n\n\n" DEF_COLOR);
    sleep(3);
}

static void log_memtests_footer(void) {
    dprintf(1, CYAN
            "\n\n\nIf you didnt see any valgrind messages it means no "
            "memory leaks were found in your program\n\n\n\n" DEF_COLOR);
}

static void log_exaustive_test20_header(void) {
    dprintf(1, HCYAN
            "Now, we will check sorting correctness with several different "
            "permutations...\n" DEF_COLOR);
}

static void log_exaustive_test20_footer(void) {
    dprintf(1, GREEN "Sorting checks are done ->	" CYAN
                     "No (FAILED) messages in the next lines will mean its "
                     "OK\n\n" DEF_COLOR);
}
