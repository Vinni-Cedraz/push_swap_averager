#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_free_arr.c"

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

int *next_permutation(int *arr, int last_index) {
    if (is_reverse_sorted(arr, last_index)) return NULL;
    int i = last_index;
    while (arr[i - 1] >= arr[i]) i--;
    int j = last_index;
    while (arr[j] <= arr[i - 1]) j--;

    int temp = arr[i - 1];
    arr[i - 1] = arr[j];
    arr[j] = temp;

    j = last_index;
    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++, j--;
    }
    return arr;
}

int **init_permutation_table(void) {
    int count = 0;
    int *arr = malloc(sizeof(int) * 5);
    int **table = calloc(sizeof(int *), 121);
    int *is_still_going_on;
    arr[0] = 1, arr[1] = 2, arr[2] = 3, arr[3] = 4, arr[4] = 5;

    do {
        if ((is_still_going_on = next_permutation(arr, 4))) {
            table[count] = malloc(sizeof(int) * 5);
            for (int i = 0; i < 5; i++) table[count][i] = arr[i];
            count++;
        }
    } while (is_still_going_on);

    free(arr);
    return table;
}

void *execute_push_swap_t1(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 1) i++;
    while (table[i][0] == 1) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", table[i][0],
                table[i][1], table[i][2], table[i][3], table[i][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t2(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 2) i++;
    while (table[i][0] == 2) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", table[i][0],
                table[i][1], table[i][2], table[i][3], table[i][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t3(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 3) i++;
    while (table[i][0] == 3) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", table[i][0],
                table[i][1], table[i][2], table[i][3], table[i][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t4(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 4) i++;
    while (table[i][0] == 4) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", table[i][0],
                table[i][1], table[i][2], table[i][3], table[i][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t5(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;

    while (**table != 5) table++;
    while (*table != NULL) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", table[0][0],
                table[0][1], table[0][2], table[0][3], table[0][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        table++;
    }
    pthread_exit(NULL);
    return NULL;
}

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    pthread_t pthread[5];
    args->table = init_permutation_table();
    pthread_create(&pthread[0], NULL, execute_push_swap_t1, (void *)args);
    pthread_create(&pthread[1], NULL, execute_push_swap_t2, (void *)args);
    pthread_create(&pthread[2], NULL, execute_push_swap_t3, (void *)args);
    pthread_create(&pthread[3], NULL, execute_push_swap_t4, (void *)args);
    pthread_create(&pthread[4], NULL, execute_push_swap_t5, (void *)args);
    int count = 0;
    while (count < 5) {
        pthread_join(pthread[count], NULL);
        count++;
    }
    printf("numbers of threads joined: %d\n", count);
    ft_free_arr((char **)args->table, (void **)args->table);
    free(args);
}
