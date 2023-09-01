#include "../include/averager.h"

void build_test_string(char memtest[], int num_args, int idx, int **table) {
    int j;
    char buffer[BUF_LEN];
    strcpy(memtest,
           "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[idx][j]);
        strcat(memtest, buffer);
    }
    strcat(memtest, " | wc -l) 2>&1");
}

void build_memtest_string(char memtest[], int num_args, int idx, int **table) {
    int j;
    char buffer[BUF_LEN];
    strcpy(memtest,
           "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap");
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
