#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ft_free_arr.c"
#include "mersenne_twister_algorithm.c"

void	ft_free_arr_size(void **arr, uint size)
{
	uint	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

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
    int *arr = malloc(sizeof(int) * 5);
    int **table = calloc(sizeof(int *), 13);
    arr[0] = -1, arr[1] = 0, arr[2] = 1, arr[3] = 2, arr[4] = 3;

    while (count < 12) {
        shuffle_array((uint *)arr, 5, rand());
        table[count] = malloc(sizeof(int) * 5);
        for (int i = 0; i < 5; i++) table[count][i] = arr[i];
        count++;
    }

    free(arr);
    return table;
}

void build_command_string(char command[5000], int i, int **table) {
    sprintf(command, "valgrind -q ./push_swap %d %d %d %d %d | ./checker %d %d %d %d %d",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
}

void build_reference_command_string(char command[5000], int i, int **table) {
    sprintf(command,
            "./push_swap %d %d %d %d %d | ./checker_linux %d %d %d %d %d",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
}

void execute_checker(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[5000];
    char reference_cmd[5000];
    char buffer[1000];
    char reference[1000];
    FILE *output;
    FILE *reference_output;
    int i = 0;

    while (table[i]) {
        build_command_string(command, i, table);
        build_reference_command_string(reference_cmd, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, 5000, output);
        fgets(reference, 5000, reference_output);
        printf("arr[%d]: { ", i);
        for (int j = 0; j < 5; j++) printf("%d ", table[i][j]);
        printf("}"); 
		printf(WHITE"\n    your checker: %sofficial checker: %s"DEF_COLOR, buffer, reference);
        if (strcmp(buffer, reference) != 0) {
            printf("ERROR\n");
            exit(1);
        }
        pclose(output);
        pclose(reference_output);
        i++;
    }
}

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_permutation_table();
	printf(WHITE"\n\n\n		Running tests with valgrind -q \n\n\n\n"DEF_COLOR);
	execute_checker(args);
    ft_free_arr_size((void **)args->table, 13);
    free(args);
}
