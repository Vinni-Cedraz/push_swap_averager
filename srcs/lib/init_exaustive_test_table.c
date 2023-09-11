#include "averager.h"

#define START_IDX_TEST20 0
#define END_IDX_TEST20 160
#define START_IDX_TEST100 160
#define END_IDX_TEST100 321
#define TEST20 20
#define TEST100 100

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

int **init_table_exaustive_tests(void) {
    int **table = calloc(sizeof(int *), 1000);
    int count;

    count = 0;
    srand(time(NULL) ^ (getpid() << 16));
    init_exaustive(&count, table, rand(), START_IDX_TEST20, END_IDX_TEST20,
                   TEST20);
    init_exaustive(&count, table, rand(), START_IDX_TEST100, END_IDX_TEST100,
                   TEST100);
    return table;
}

void init_exaustive(int *count, int **table, int rand, int i_start, int i_end,
                    int arr_size) {
    while (*count != i_start)
        (*count)++;
    int *arr = malloc(sizeof(int) * arr_size);
    for (int i = 0; i < arr_size; i++)
        arr[i] = i;
    while (*count < i_end) {
        if (*count && (*count % 20) == 0)
            table[*count] = NULL;
        else {
            shuffle_array((uint *)arr, arr_size, rand);
            table[*count] = calloc(sizeof(int), arr_size);
            for (int i = 0; i < arr_size; i++)
                table[*count][i] = arr[i];
        }
        (*count)++;
    }
    free(arr);
}
