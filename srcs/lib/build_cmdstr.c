#include "averager.h"

void build_averager_test_cmd_string(char command[], int num_args, int idx, int **table) {
    int j;
    char buffer[5];
    strcpy(command, "(./push_swap");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[idx][j]);
        strcat(command, buffer);
    }
    strcat(command, " | wc -l) 2>&1");
}

void build_exaustive_checker_test_cmd_string(char *command, int num_args, int i, int **table) {
    int j;
    char buffer[5];
    strcpy(command, "(./push_swap");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[i][j]);
        strcat(command, buffer);
    }
    strcat(command, " | ./checker_linux");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[i][j]);
        strcat(command, buffer);
    }
    strcat(command, ") 2>&1");
}

void build_size3_sorting_cmdstr(char memtest[], int num_args, int idx, int **table) {
    int j;
    char buffer[5];
    strcpy(memtest, "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[idx][j]);
        strcat(memtest, buffer);
    }
    strcat(memtest, " | wc -l) 2>&1");
}

void build_memtest_cmdstring(char memtest[], int num_args, int idx, int **table) {
    int j;
    char buffer[5];
    strcpy(memtest, "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[idx][j]);
        strcat(memtest, buffer);
    }
    strcat(memtest, " | ./checker_linux");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[idx][j]);
        strcat(memtest, buffer);
    }
    strcat(memtest, ") 2>&1");
}
