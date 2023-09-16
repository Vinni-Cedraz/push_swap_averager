#include "../include/averager.h"

static void init_memtest_table(int *index, int **table, int rand, int arr_size);

static void print_table(int **table, int numRows, int arr_size) {
    for (int i = 0; i < numRows; i++) {
        if (table[i] != NULL) {
            printf(BLUE "Table[%d]: " DEF_COLOR, i);
            for (int j = 0; j < arr_size; j++) {
                printf("%d ", table[i][j]);
            }
            printf("\n");
        } else {
            printf(RED "Table[%d]: NULL\n" DEF_COLOR, i);
        }
    }
}

int **init_table_memtests_sizes(void) {
    int **table = calloc(sizeof(int *), 1000);
    srand(time(NULL) ^ (getpid() << 16));
    int index = 1;
    init_memtest_table(&index, table, rand(), 3);
    init_memtest_table(&index, table, rand(), 5);
    init_memtest_table(&index, table, rand(), 10);
    init_memtest_table(&index, table, rand(), 15);
    init_memtest_table(&index, table, rand(), 20);
    init_memtest_table(&index, table, rand(), 100);
    init_memtest_table(&index, table, rand(), 500);
    return (table);
}

static void init_memtest_table(int *index, int **table, int rand, int arr_size) {
    int *arr = malloc(sizeof(int) * arr_size);
    for (int i = 1; i < arr_size + 1; i++)
        arr[i - 1] = i;
    if (3 == arr_size) {
        int *going_on;
        while ((going_on = next_permutation(arr, 2))) {
            table[*index] = calloc(sizeof(int), 3);
            for (int i = 0; i < 3; i++)
                table[*index][i] = arr[i];
            (*index)++;
        }
        (*index)++;
        free(arr);
    } else {
        for (int three = 0; three < 3; three++) {
            shuffle_array((uint *)arr, arr_size, rand);
            table[*index] = calloc(sizeof(int), arr_size);
            for (int i = 0; i < arr_size; i++)
                table[*index][i] = arr[i];
            (*index)++;
        }
        (*index)++;
        free(arr);
    }
}
