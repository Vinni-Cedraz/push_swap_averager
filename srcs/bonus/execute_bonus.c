#include "../include/averager.h"

static void print_message(char *reference, char *buffer, t_args *args);
static void print_ok_ko(char *reference, char *buffer);

void execute_bonus(void *args_void) {
    t_args *args = (t_args *)args_void;
    char command[HUGE_CMD_LEN];
    char reference_cmd[HUGE_CMD_LEN];
    char buffer[BUF_LEN];
    char reference[BUF_LEN];
    FILE *output;
    FILE *reference_output;
	int	idx = args->sizes_and_idx.tab_idx - 1;

    while (args->table[++idx]) {
        build_bonus_string(command, args->sizes_and_idx, args->table);
        build_bonus_reference_string(reference_cmd, args->sizes_and_idx, args->table);
        execute_cmd(command, buffer, output);
        execute_cmd(reference_cmd, reference, reference_output);
        print_message(reference, buffer, args);
    }
}

static inline void print_message(char *reference, char *buffer, t_args *args) {
    t_action size_and_idx = args->sizes_and_idx;
    printf(HBLUE "size(%d):" DEF_COLOR "{ ", size_and_idx.arr_size);
    for (int j = 0; j < size_and_idx.arr_size; j++) printf("%d ", args->table[size_and_idx.tab_idx][j]);
    printf("}\n");
    print_ok_ko(reference, buffer);
}

static inline void print_ok_ko(char *reference, char *buffer) {
    if (!strncmp(reference, "OK", 2))
        printf(CYAN "official checker: " GREEN "OK\n" DEF_COLOR);
    else if (strncmp(reference, "KO", 2))
        printf(CYAN "official checker: " RED "KO\n" DEF_COLOR);
    if (!strncmp(buffer, "OK", 2))
        printf(HCYAN "    your checker: " HGREEN "OK\n" DEF_COLOR);
    else if (!strncmp(buffer, "KO", 2))
        printf(HCYAN "    your checker: " HRED "KO\n" DEF_COLOR);
    if (strcmp(buffer, reference) != 0) {
        printf(HRED "ERROR\n" DEF_COLOR);
        exit(1);
    }
}
