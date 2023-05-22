#include "../include/averager.h"

int **init_table2(void) {
    int **table = calloc(sizeof(int *), 1000);
    srand(time(NULL) ^ (getpid() << 16));
    int count = 299;
    init_exaustive(&count, table, rand(), 299, 459, 100);
    return table;
}

void init_exaustive(int *count, int **table, int rand, int i_start, int i_end, int arr_size) {
    while (*count != i_start) (*count)++;
    int *arr = malloc(sizeof(int) * arr_size);
    for (int i = 0; i < arr_size; i++) arr[i] = i;  // init sequential array
    while (*count < i_end) {
        shuffle_array((uint *)arr, arr_size, rand);
        table[*count] = calloc(sizeof(int), arr_size);
        for (int i = 0; i < arr_size; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    free(arr);
}
