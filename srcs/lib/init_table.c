#include "averager.h"

static void init(int *index, int **table, int rand, int arr_size);

int **init_table(void) {
    int **table = calloc(sizeof(int *), 1000);
    srand(time(NULL) ^ (getpid() << 16));
    int index = 1;
    init(&index, table, rand(), 3);
    init(&index, table, rand(), 5);
    init(&index, table, rand(), 10);
    init(&index, table, rand(), 15);
    init(&index, table, rand(), 20);
    init(&index, table, rand(), 100);
    init(&index, table, rand(), 500);

    init_exaustive(&index, table, rand(), 99, 259, 20);
    return (table);
}

static void init(int *index, int **table, int rand, int arr_size) {
    int *arr = malloc(sizeof(int) * arr_size);
    for (int i = 1; i < arr_size + 1; i++) arr[i - 1] = i;
    if (3 == arr_size) {
        int *going_on;
        while ((going_on = next_permutation(arr, 2))) {
            table[*index] = calloc(sizeof(int), 3);
            for (int i = 0; i < 3; i++) table[*index][i] = arr[i];
            (*index)++;
        }
        (*index)++;
        free(arr);
    } else {
        for (int three = 0; three < 3; three++) {
            shuffle_array((uint *)arr, arr_size, rand);
            table[*index] = calloc(sizeof(int), arr_size);
            for (int i = 0; i < arr_size; i++) table[*index][i] = arr[i];
            (*index)++;
        }
        (*index)++;
        free(arr);
    }
}
