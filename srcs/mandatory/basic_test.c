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
    FILE *output;

    dprintf(1, WHITE "\nMEMORY AND SORTING TESTS\n" DEF_COLOR CYAN
                     "	with valgrind -q \n\n\n" DEF_COLOR);

    execute_memtest(table, size(), 01, buffer, cmd, build_memtest3_string);
    execute_memtest(table, size(), 01, buffer, cmd, build_test3_string);
    execute_memtest(table, size(), 07, buffer, cmd, build_memtest5_string);
    execute_memtest(table, size(), 11, buffer, cmd, build_memtest10_string);
    execute_memtest(table, size(), 15, buffer, cmd, build_memtest15_string);
    execute_memtest(table, size(), 19, buffer, cmd, build_memtest20_string);
    execute_memtest(table, size(), 27, buffer, cmd, build_memtest100_string);
    execute_memtest(table, size(), 31, buffer, cmd, build_memtest500_string);
}

static int size(void) {
    static short call_counter;
    call_counter++;
    if (call_counter == 1) return 3;
    if (call_counter == 2) return 3;
    if (call_counter == 3) return 5;
    if (call_counter == 4) return 10;
    if (call_counter == 5) return 15;
    if (call_counter == 6) return 20;
    if (call_counter == 7) return 100;
    if (call_counter == 8) return 500;
}

static void log_memtests_header(void) {
    dprintf(1, HRED
            "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "
            "FLAG\n\n\n" DEF_COLOR);
    sleep(3);
    dprintf(1, WHITE "BASIC TESTS\n" DEF_COLOR);
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
