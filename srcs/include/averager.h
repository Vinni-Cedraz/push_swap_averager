#ifndef AVERAGER_H
#define AVERAGER_H

// SYSTEM HEADERS
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// COLORS
#define GREEN "\033[0;32m"
#define HGREEN "\033[1;32m"
#define DEF_COLOR "\033[0;39m"
#define CYAN "\033[0;36m"
#define HCYAN "\033[1;36m"
#define WHITE "\033[1;97m"
#define MAGENTA "\033[0;35m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define HBLUE "\033[1;34m"
#define HRED "\033[1;31m"
#define RED "\033[0;91m"

// LENGTHS
#define MT_LEN 624
#define MT_IA 397
#define BUF_LEN 100
#define CMD_LEN 500
#define MEDIUM_CMD_LEN 1500
#define BIG_CMD_LEN 3000
#define HUGE_CMD_LEN 10000

#define CMD_OUTPUT 1
#define LOG_FILE 0
#define CLOSE_PROCESS_AFTER 1
#define DONT_CLOSE_PROCESS_AFTER 0
#define TRUE 1
#define FALSE 0
#define BONUS 1

#define MEMORY_TEST_HEADER                                                                                             \
    HRED "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "                                                         \
         "FLAG\n\n\n" DEF_COLOR

#define MEMORY_TEST_MESSAGE                                                                                            \
    WHITE "\nMEMORY AND SORTING TESTS\n" DEF_COLOR CYAN "		with valgrind on quiet mode (-q flag) "                     \
          "\n\n\n" DEF_COLOR

#define MEMORY_TEST_FOOTER                                                                                             \
    CYAN "\n\n\nIf you didnt see any valgrind messages it means no memory "                                            \
         "leaks were found in your program\n\n\n\n" DEF_COLOR

#define EXAUSTIVE_TEST20_HEADER                                                                                        \
    HCYAN "Now, we will check sorting correctness with several different "                                             \
          "permutations...\n" DEF_COLOR

// USER DEFINED TYPES
typedef unsigned int uint;
typedef void(t_build_cmdstr)(char[], int, int, int **);
typedef void(t_fprintf_result_to_file)(char[], FILE *, bool *);

typedef struct MT {
    uint state[MT_LEN];
    int next;
} t_MT;

typedef struct s_uargs {
    uint **table;
    char *tmp_file;
    int thread_idx;
    t_build_cmdstr *build_cmd_string;
    t_fprintf_result_to_file *fprintf_result_to_file;
    bool error;
    int size;
} t_uargs;

typedef struct s_action {
    int arr_size;
    int tab_idx;
    bool is_sorting_test;
    t_build_cmdstr *build_cmd;
} t_action;

typedef struct s_args {
    int **table;
    char *tmp_file;
    int thread_idx;
    t_build_cmdstr *build_cmdstr;
    t_fprintf_result_to_file *fprintf_result_to_file;
    bool error;
    int size;
    t_action sizes_and_idx;
} t_args;

// FUNCTION PROTOTYPES
void fprintf_nb_of_op(char *out_str, FILE *fp, bool *error);
int is_repeated100(uint **table, uint *tmp_arr, int count);
int is_repeated500(uint **table, uint *tmp_arr, int count);
int *next_permutation(int *arr, int last_index);
uint *seq_except(int exclude);
int *next_permutation(int *arr, int last_index);
void ft_free_arr(char **arr, void **aux);
void ft_free_arr_size(void **arr, uint size);
void shuffle_array(uint *arr, int len, uint seed);
void build_bonus_string(char cmd[], t_action size_and_idx, int **table);
void build_bonus_reference_string(char cmd[], t_action size_and_idx, int **table);
int **init_table_memtests_sizes(void);
void fprintf_ok_ko(char *out_str, FILE *fp, bool *GLOBAL);
void create_unified_log_file20(void);
void create_unified_log_file100(void);
int handle_err(int **table, int size, int i, char *buffer);
void log_error(bool empty_expected, char *out_str, char *cmd);
void log_cmd_and_output(int **table, int size, int i, char *buf);
void log_cmd_and_output_3(int **table, int size, int i, char *buf);
void build_memtest_cmdstring(char memtest[], int i, int num_args, int **table);
void build_size3_sorting_cmdstr(char memtest[], int num_args, int idx, int **table);
void exec_memtest(int **table, t_action sizes_and_action);
void init_exaustive(int *count, int **table, int rand, int i_start, int i_end, int arr_size);
void bonus_log_error(bool empty_expected, char *out_str);
void open_process_and_exec_cmd_there(FILE **fp, char *cmd, bool close);
void build_exaustive_checker_test_cmd_string(char command[], int num_args, int idx, int **table);
void build_averager_test_cmd_string(char command[], int num_args, int idx, int **table);
void trim_linebreak(char *str);
void max_int_overf(char *program_name);
void duplicate_sorted(char *program_name);
void duplicate_arg(char *program_name);
void no_args(char *program_name);
void empty_string(char *program_name);
void b_invalid_action(char *program_name);
void b_whitespaced_action(char *program_name);
void non_numeric1(char *program_name);
void non_numeric2(char *program_name);
void non_numeric3(char *program_name);
void non_numeric4(char *program_name);
void non_numeric5(char *program_name);
void non_numeric6(char *program_name);
void non_numeric_empty_string(char *program_name);
void duplicate_arguments(char *program_name);
int **init_table_exaustive_tests(void);
void *execute_push_swap_thread(void *args_void);
void print_array_to_file(FILE *fp, int idx, int arr_size, uint **table);
char *execute_cmd(char cmd[], char buffer[], FILE *output);
void exec_each_function_in(void (*array_of_function_ptrs[])(char *str), char *str);
void analyse_cmd_output(char line[500], FILE *fp, char cmd[500], bool bonus);
void exec_test_and_analyse_output(char *cmd, bool empty_expected, bool bonus);
void execute_bonus(void *args_void);

#endif
