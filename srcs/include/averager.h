#ifndef AVERAGER_H
#define AVERAGER_H

// SYSTEM HEADERS
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
// include for  booleans
#include <stdbool.h>

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
#define MT_LEN 624
#define MT_IA 397

#define EMPTY_EXPECTED 1
#define EMPTY_NOT_EXPECTED 0
#define CLOSE_PROCESS_AFTER 1
#define DONT_CLOSE_PROCESS_AFTER 0

#define MEMORY_TEST_HEADER                                                     \
    HRED "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "                 \
         "FLAG\n\n\n" DEF_COLOR

#define MEMORY_TEST_MESSAGE                                                    \
    WHITE "\nMEMORY AND SORTING TESTS\n" DEF_COLOR CYAN                        \
          "		with valgrind on quiet mode (-q flag) \n\n\n" DEF_COLOR

#define MEMORY_TEST_FOOTER                                                     \
    CYAN "\n\n\nIf you didnt see any valgrind messages it means no memory "    \
         "leaks were found in your program\n\n\n\n" DEF_COLOR

#define EXAUSTIVE_TEST20_HEADER                                                \
    HCYAN "Now, we will check sorting correctness with several different "     \
          "permutations...\n" DEF_COLOR

#define EXAUSTIVE_TEST20_FOOTER                                                \
    GREEN "Sorting checks are done ->	" CYAN                                 \
          "No (FAILED) messages in the next line will mean its "               \
          "OK\n\n" DEF_COLOR

// USER DEFINED TYPES
typedef unsigned int uint;
typedef void(t_build_cmdstr)(char[], int, int **);

typedef struct MT {
    uint state[MT_LEN];
    int next;
} t_MT;

typedef struct s_args {
    int **table;
} t_args;

typedef struct s_uargs {
    uint **table;
} t_uargs;

// FUNCTION PROTOTYPES
int is_repeated100(uint **table, uint *tmp_arr, int count);
int is_repeated500(uint **table, uint *tmp_arr, int count);
int *next_permutation(int *arr, int last_index);
uint *seq_except(int exclude);
int *next_permutation(int *arr, int last_index);
void ft_free_arr(char **arr, void **aux);
void ft_free_arr_size(void **arr, uint size);
void shuffle_array(uint *arr, int len, uint seed);
void execute_bonus5(void *args_void);
void execute_bonus10(void *args_void);
void execute_bonus15(void *args_void);
void execute_bonus20(void *args_void);
void execute_bonus100(void *args_void);
void execute_bonus500(void *args_void);
void execute_bonus1000(void *args_void);
void build_bonus5_string(char memtest[], int i, int **table);
void build_reference5_string(char command[5000], int i, int **table);
void build_bonus10_string(char memtest[], int i, int **table);
void build_reference10_string(char memtest[], int i, int **table);
void build_bonus15_string(char memtest[], int i, int **table);
void build_reference15_string(char memtest[], int i, int **table);
void build_bonus20_string(char memtest[], int i, int **table);
void build_reference20_string(char memtest[], int i, int **table);
void build_bonus100_string(int i, int **table, char command[]);
void build_reference100_string(int i, int **table, char command[]);
void build_bonus500_string(int i, int **table, char command[]);
void build_reference500_string(int i, int **table, char command[]);
void build_bonus1000_string(int i, int **table, char *command);
void build_reference1000_string(int i, int **table, char *command);
int **init_table(void);
int **init_table2(void);
void max_int_overf(char *cmd);
void non_numeric(char *cmd);
void duplicate_sorted(char *cmd);
void duplicate_arg(char *cmd);
void no_args(char *cmd);
void empty_string(char *cmd);
void invalid_action(char *cmd);
void whitespaced_action(char *cmd);
void exaustive_test20(void *args_void);
void exaustive_test100(void *args_void);
void fprintf_ok_ko(char *out_str, FILE *fp, bool *GLOBAL);
void create_unified_log_file20(void);
void create_unified_log_file100(void);
int handle_err(int **table, int size, int i, char *buffer);
void log_error(bool empty_expected, char *out_str, char *cmd);
void log_cmd_and_output(int **table, int size, int i, char *buf);
void log_cmd_and_output_3(int **table, int size, int i, char *buf);
void build_test3_string(char memtest[], int i, int **table);
void build_memtest3_string(char memtest[], int i, int **table);
void build_memtest5_string(char memtest[], int i, int **table);
void build_memtest10_string(char memtest[], int i, int **table);
void build_memtest15_string(char memtest[], int i, int **table);
void build_memtest20_string(char memtest[], int i, int **table);
void build_memtest100_string(char memtest[], int i, int **table);
void build_memtest500_string(char memtest[], int i, int **table);
void exec_memtest(int **table, int size, int table_index, char buffer[],
                  char cmd[], t_build_cmdstr build_cmdstr);
void init_exaustive(int *count, int **table, int rand, int i_start, int i_end,
                    int arr_size);
void bonus_log_error(bool empty_expected, char *out_str);
void open_process_and_exec_cmd_there(FILE **fp, char *cmd, bool close);
void trim_linebreak(char *str);

#endif
