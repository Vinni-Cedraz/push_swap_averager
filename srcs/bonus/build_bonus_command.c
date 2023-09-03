
#include "../include/averager.h"

void build_bonus_string(char cmd[], int num_args, int idx, int **table) {
    int j;
    char buffer[5];
    strcpy(cmd, "(valgrind -q ./push_swap");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[idx][j]);
        strcat(cmd, buffer);
    }
    strcat(cmd, " | ./checker_linux");
    for (j = 0; j < num_args; j++) {
        sprintf(buffer, " %d", table[idx][j]);
        strcat(cmd, buffer);
    }
    strcat(cmd, ") 2>&1");
}

void build_bonus_reference_string(char cmd[], int n, int i, int **table) {
    int j;
    char buffer[5];
    strcpy(cmd, "./push_swap");
    for (j = 0; j < n; j++) {
        sprintf(buffer, " %d", table[i][j]);
        strcat(cmd, buffer);
    }
    strcat(cmd, " | ./checker_linux");
    for (j = 0; j < n; j++) {
        sprintf(buffer, " %d", table[i][j]);
        strcat(cmd, buffer);
    }
}
