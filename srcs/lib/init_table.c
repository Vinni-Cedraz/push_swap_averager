#include "averager.h"

static void init3(int *count, int **table, int rand);
static void init5(int *count, int **table, int rand);
static void init10(int *count, int **table, int rand);
static void init15(int *count, int **table, int rand);
static void init20(int *count, int **table, int rand);
static void init100(int *count, int **table, int rand);
static void init500(int *count, int **table, int rand);
static void init1000(int *count, int **table, int rand);
static void init_exaustive_20(int *count, int **table, int rand);

int **init_table(void) {
    int *arr = NULL;
    int **table = calloc(sizeof(int *), 500);
    srand(time(NULL) ^ (getpid() << 16));
    int count = 1;
    init3(&count, table, rand());
    init5(&count, table, rand());
    init10(&count, table, rand());
    init15(&count, table, rand());
    init20(&count, table, rand());
    init100(&count, table, rand());
    init500(&count, table, rand());
    init1000(&count, table, rand());
    init_exaustive_20(&count, table, rand());

    return (table);
}

static void init3(int *count, int **table, int rand) {
    int *arr = malloc(sizeof(int) * 3);
    for (int i = 1; i < 4; i++) arr[i - 1] = i;

    int *going_on;
    while ((going_on = next_permutation(arr, 2))) {
        table[*count] = calloc(sizeof(int), 3);
        for (int i = 0; i < 3; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    (*count)++;
    free(arr);
}

static void init5(int *count, int **table, int rand) {
    if (*count != 7) {
        printf("Error: count == %d\n", *count);
        exit(1);
    }
    int *arr = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) arr[i] = i;
    while (*count < 10) {
        shuffle_array((uint *)arr, 5, rand);
        table[*count] = calloc(sizeof(int), 5);
        for (int i = 0; i < 5; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    (*count)++;
    free(arr);
}

static void init10(int *count, int **table, int rand) {
    if (*count != 11) {
        printf("Error: count == %d\n", *count);
        exit(1);
    }
    int *arr = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) arr[i] = i - 5;
    while (*count < 14) {
        shuffle_array((uint *)arr, 10, rand);
        table[*count] = calloc(sizeof(int), 10);
        for (int i = 0; i < 10; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    (*count)++;
    free(arr);
}

static void init15(int *count, int **table, int rand) {
    if (*count != 15) {
        printf("Error: count != 12\n");
        exit(1);
    }
    int *arr = malloc(sizeof(int) * 15);
    for (int i = 0; i < 15; i++) arr[i] = i - 5;
    while (*count < 18) {
        shuffle_array((uint *)arr, 15, rand);
        table[*count] = calloc(sizeof(int), 15);
        for (int i = 0; i < 15; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    free(arr);
    (*count)++;
}

static void init20(int *count, int **table, int rand) {
    if (*count != 19) {
        printf("Error: count != 16\n");
        exit(1);
    }
    int *arr = malloc(sizeof(int) * 20);
    for (int i = 0; i < 20; i++) arr[i] = i;
    while (*count < 22) {
        shuffle_array((uint *)arr, 20, rand);
        table[*count] = calloc(sizeof(int), 20);
        for (int i = 0; i < 20; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    free(arr);
    *count = 27;
}

static void init100(int *count, int **table, int rand) {
    if (*count != 27) {
        printf("Error: count != 24\n");
        exit(1);
    }
    int *arr = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++) arr[i] = i;
    while (*count < 30) {
        shuffle_array((uint *)arr, 100, rand);
        table[*count] = calloc(sizeof(int), 100);
        for (int i = 0; i < 100; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    free(arr);
    (*count)++;
}

static void init500(int *count, int **table, int rand) {
    if (*count != 31) {
        printf("Error: count != 28\n");
        exit(1);
    }
    int *arr = malloc(sizeof(int) * 500);
    for (int i = 0; i < 500; i++) arr[i] = i;
    while (*count < 34) {
        shuffle_array((uint *)arr, 500, rand);
        table[*count] = calloc(sizeof(int), 500);
        for (int i = 0; i < 500; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    free(arr);
    (*count)++;
}

static void init1000(int *count, int **table, int rand) {
    if (*count != 35) {
        printf("Error: count != 32\n");
        exit(1);
    }
    int *arr = malloc(sizeof(int) * 1000);
    for (int i = 0; i < 1000; i++) arr[i] = i;
    shuffle_array((uint *)arr, 1000, rand);
    table[*count] = calloc(sizeof(int), 1000);
    for (int i = 0; i < 1000; i++) table[*count][i] = arr[i];
    (*count)++;
    free(arr);
}

static void init_exaustive_20(int *count, int **table, int rand) {
    if (*count != 36) {
        printf("Error: count != 36\n");
        exit(1);
    }
	while (*count != 99) (*count)++;
    int *arr = malloc(sizeof(int) * 20);
    for (int i = 0; i < 20; i++) arr[i] = i;
    while (*count < 258) {
        shuffle_array((uint *)arr, 20, rand);
        table[*count] = calloc(sizeof(int), 20);
        for (int i = 0; i < 20; i++) table[*count][i] = arr[i];
        (*count)++;
    }
    free(arr);
}

static void init_exaustive100(int *count, int **table, int rand) {
	if (*count != 258) {
		printf("Error: count != 258\n");
		exit(1);
	}
	while (*count != 299) (*count)++;
	int *arr = malloc(sizeof(int) * 100);
	for (int i = 0; i < 100; i++) arr[i] = i;
	while (*count < 458) {
		shuffle_array((uint *)arr, 100, rand);
		table[*count] = calloc(sizeof(int), 100);
		for (int i = 0; i < 100; i++) table[*count][i] = arr[i];
		(*count)++;
	}
	free(arr);
}
