
#include "../include/averager.h"

void build_bonus_string(char cmd[], t_action size_and_idx, int **table) {
    char buffer[5];
    strcpy(cmd, "(valgrind -q ./push_swap");
    for (int j = 0; j < size_and_idx.arr_size; j++) {
        sprintf(buffer, " %d", table[size_and_idx.tab_idx][j]);
        strcat(cmd, buffer);
    }
    strcat(cmd, " | ./checker_linux");
    for (int j = 0; j < size_and_idx.arr_size; j++) {
        sprintf(buffer, " %d", table[size_and_idx.tab_idx][j]);
        strcat(cmd, buffer);
    }
    strcat(cmd, ") 2>&1");
}

void build_bonus_reference_string(char cmd[], t_action size_and_idx, int **table) {
    char buffer[5];
    strcpy(cmd, "./push_swap");
    for (int j = 0; j < size_and_idx.arr_size; j++) {
        sprintf(buffer, " %d", table[size_and_idx.tab_idx][j]);
        strcat(cmd, buffer);
    }
    strcat(cmd, " | ./checker_linux");
    for (int j = 0; j < size_and_idx.arr_size; j++) {
        sprintf(buffer, " %d", table[size_and_idx.tab_idx][j]);
        strcat(cmd, buffer);
    }
}
