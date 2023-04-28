#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "ft_free_arr.c"
#include "mersenne_twister_algorithm.c"

typedef struct s_args {
    int **table;
} t_args;

int is_reverse_sorted(int *arr, int last_index) {
    for (int i = 0; i < last_index; i++)
        if (arr[i] < arr[i + 1]) return 0;
    return 1;
}

void print_arr(int *arr, int last_index) {
    for (int i = 0; i <= last_index; i++) printf("%d ", arr[i]);
    printf("\n");
}

int **init_permutation_table(void) {
    int count = 0;
    int *arr = malloc(sizeof(int) * 20);
    int **table = calloc(sizeof(int *), 11);
	for (int i = 0; i < 20; i++) arr[i] = i - 10;

    while (count < 10) {
        shuffle_array((uint *)arr, 20, rand());
        table[count] = malloc(sizeof(int) * 20);
        for (int i = 0; i < 20; i++) table[count][i] = arr[i];
        count++;
    }

    free(arr);
    return table;
}

void build_memtest_string(char memtest[5000], int i, int **table) {
    sprintf(memtest,
            "valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d |"
			"./checker_linux %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
            table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
            table[i][15], table[i][16], table[i][17], table[i][18], table[i][19]);
}

void execute_memtest(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[5000];
    char buffer[1000];
    FILE *output;
    int i = 0;

    while (table[i]) {
        build_memtest_string(command, i, table);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("arr[%d]: { ", i);
        for (int j = 0; j < 20; j++) printf("%d ", table[i][j]);
        printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
        if (strncmp(buffer, "OK\n", 2) != 0) {
            printf("ERROR\n");
            exit(1);
        }
        pclose(output);
        i++;
    }
}


int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_permutation_table();
	printf("\n\n\n		Running tests with valgrind -q \n\n\n\n");
	execute_memtest(args);
	ft_free_arr((char **)args->table, (void **)args->table);
    free(args);
    printf("\n\n\nIf you didnt see any valgrind messages it means no "
           "memory leaks were found in your program\n\n\n\n");
}
