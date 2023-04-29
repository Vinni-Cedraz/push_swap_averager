#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void print_arr_table(int **table, int last_index) {
    for (int i = 0; i <= last_index; i++) {
        if (table[i] == NULL) continue;
        for (int j = 0; j <= 999; j++) printf("%d ", table[i][j]);
        printf("\n");
    }
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
    // size 3
    int count = 0;
    int *arr = malloc(sizeof(int) * 3);
    int **table = calloc(sizeof(int *), 100);
    arr[0] = -1, arr[1] = 0, arr[2] = 1;
    int *is_still_going_on = next_permutation(arr, 2);

    while (is_still_going_on) {
        is_still_going_on = next_permutation(arr, 2);
        table[count] = calloc(sizeof(int), 3);
        for (int i = 0; i < 3; i++) table[count][i] = arr[i];
        count++;
    }
    free(arr);
    count += 2;

    // size 5
    if (count != 7) {
        printf("Error: count == %d\n", count);
        exit(1);
    }
    arr = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) arr[i] = i;
    srand(time(NULL) ^ (getpid() << 16));
    while (count < 10) {
        shuffle_array((uint *)arr, 5, rand());
        table[count] = calloc(sizeof(int), 5);
        for (int i = 0; i < 5; i++) table[count][i] = arr[i];
        count++;
    }
    count++;
    free(arr);

    // size 10
    if (count != 11) {
        printf("Error: count == %d\n", count);
        exit(1);
    }
    arr = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) arr[i] = i - 5;
    srand(time(NULL) ^ (getpid() << 16));
    while (count < 14) {
        shuffle_array((uint *)arr, 10, rand());
        table[count] = calloc(sizeof(int), 10);
        for (int i = 0; i < 10; i++) table[count][i] = arr[i];
        count++;
    }
    count++;
    free(arr);

    // size 15
    if (count != 15) {
        printf("Error: count != 12\n");
        exit(1);
    }
    arr = malloc(sizeof(int) * 15);
    for (int i = 0; i < 15; i++) arr[i] = i - 5;
    srand(time(NULL) ^ (getpid() << 16));
    while (count < 18) {
        shuffle_array((uint *)arr, 15, rand());
        table[count] = calloc(sizeof(int), 15);
        for (int i = 0; i < 15; i++) table[count][i] = arr[i];
        count++;
    }
    free(arr);
    count++;

    // size 20
    if (count != 19) {
        printf("Error: count != 16\n");
        exit(1);
    }
    arr = malloc(sizeof(int) * 20);
    for (int i = 0; i < 20; i++) arr[i] = i;
    srand(time(NULL) ^ (getpid() << 16));
    while (count < 22) {
        shuffle_array((uint *)arr, 20, rand());
        table[count] = calloc(sizeof(int), 20);
        for (int i = 0; i < 20; i++) table[count][i] = arr[i];
        count++;
    }
    free(arr);
    count = 27;

    // size 100
    if (count != 27) {
        printf("Error: count != 24\n");
        exit(1);
    }
    arr = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++) arr[i] = i;
    srand(time(NULL) ^ (getpid() << 16));
    while (count < 30) {
        shuffle_array((uint *)arr, 100, rand());
        table[count] = calloc(sizeof(int), 100);
        for (int i = 0; i < 100; i++) table[count][i] = arr[i];
        count++;
    }
    free(arr);
    count++;

    // size 500
    if (count != 31) {
        printf("Error: count != 28\n");
        exit(1);
    }
    arr = malloc(sizeof(int) * 500);
    for (int i = 0; i < 500; i++) arr[i] = i;
    srand(time(NULL) ^ (getpid() << 16));
    while (count < 34) {
        shuffle_array((uint *)arr, 500, rand());
        table[count] = calloc(sizeof(int), 500);
        for (int i = 0; i < 500; i++) table[count][i] = arr[i];
        count++;
    }
    free(arr);
    count++;

    // size 1000
    if (count != 35) {
        printf("Error: count != 32\n");
        exit(1);
    }
    arr = malloc(sizeof(int) * 1000);
    for (int i = 0; i < 1000; i++) arr[i] = i;
    srand(time(NULL) ^ (getpid() << 16));
    while (count < 38) {
        shuffle_array((uint *)arr, 1000, rand());
        table[count] = calloc(sizeof(int), 1000);
        for (int i = 0; i < 1000; i++) table[count][i] = arr[i];
        count++;
    }
    free(arr);

    // print_arr_table(table, 35);
    return (table);
}

void build_memtest3_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "valgrind -q ./push_swap %d %d %d |"
            "./checker_linux %d %d %d",
            table[i][0], table[i][1], table[i][2], table[i][0], table[i][1],
            table[i][2]);
}

void build_memtest5_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "valgrind -q ./push_swap %d %d %d %d %d |"
            "./checker_linux %d %d %d %d %d",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
}

void build_memtest10_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d |"
            "./checker_linux %d %d %d %d %d %d %d %d %d %d",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9]);
}

void build_memtest15_string(char memtest[], int i, int **table) {
    sprintf(
        memtest,
        "valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d |"
        "./checker_linux %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14]);
}

void build_memtest20_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d |"
            "./checker_linux %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13],
            table[i][14], table[i][15], table[i][16], table[i][17],
            table[i][18], table[i][19], table[i][0], table[i][1], table[i][2],
            table[i][3], table[i][4], table[i][5], table[i][6], table[i][7],
            table[i][8], table[i][9], table[i][10], table[i][11], table[i][12],
            table[i][13], table[i][14], table[i][15], table[i][16],
            table[i][17], table[i][18], table[i][19]);
}

void build_memtest100_string(int i, int **table, char command[]) {
    sprintf(
        command,
        "valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | ./checker_linux %d "
        "%d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][20], table[i][21], table[i][22], table[i][23], table[i][24],
        table[i][25], table[i][26], table[i][27], table[i][28], table[i][29],
        table[i][30], table[i][31], table[i][32], table[i][33], table[i][34],
        table[i][35], table[i][36], table[i][37], table[i][38], table[i][39],
        table[i][40], table[i][41], table[i][42], table[i][43], table[i][44],
        table[i][45], table[i][46], table[i][47], table[i][48], table[i][49],
        table[i][50], table[i][51], table[i][52], table[i][53], table[i][54],
        table[i][55], table[i][56], table[i][57], table[i][58], table[i][59],
        table[i][60], table[i][61], table[i][62], table[i][63], table[i][64],
        table[i][65], table[i][66], table[i][67], table[i][68], table[i][69],
        table[i][70], table[i][71], table[i][72], table[i][73], table[i][74],
        table[i][75], table[i][76], table[i][77], table[i][78], table[i][79],
        table[i][80], table[i][81], table[i][82], table[i][83], table[i][84],
        table[i][85], table[i][86], table[i][87], table[i][88], table[i][89],
        table[i][90], table[i][91], table[i][92], table[i][93], table[i][94],
        table[i][95], table[i][96], table[i][97], table[i][98], table[i][99],
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][20], table[i][21], table[i][22], table[i][23], table[i][24],
        table[i][25], table[i][26], table[i][27], table[i][28], table[i][29],
        table[i][30], table[i][31], table[i][32], table[i][33], table[i][34],
        table[i][35], table[i][36], table[i][37], table[i][38], table[i][39],
        table[i][40], table[i][41], table[i][42], table[i][43], table[i][44],
        table[i][45], table[i][46], table[i][47], table[i][48], table[i][49],
        table[i][50], table[i][51], table[i][52], table[i][53], table[i][54],
        table[i][55], table[i][56], table[i][57], table[i][58], table[i][59],
        table[i][60], table[i][61], table[i][62], table[i][63], table[i][64],
        table[i][65], table[i][66], table[i][67], table[i][68], table[i][69],
        table[i][70], table[i][71], table[i][72], table[i][73], table[i][74],
        table[i][75], table[i][76], table[i][77], table[i][78], table[i][79],
        table[i][80], table[i][81], table[i][82], table[i][83], table[i][84],
        table[i][85], table[i][86], table[i][87], table[i][88], table[i][89],
        table[i][90], table[i][91], table[i][92], table[i][93], table[i][94],
        table[i][95], table[i][96], table[i][97], table[i][98], table[i][99]);
}

void build_memtest500_string(int i, int **table, char command[]) {
    sprintf(
        command,
        "valgrind -q ./push_swap "
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | "
  		"./checker_linux "
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][20], table[i][21], table[i][22], table[i][23], table[i][24],
        table[i][25], table[i][26], table[i][27], table[i][28], table[i][29],
        table[i][30], table[i][31], table[i][32], table[i][33], table[i][34],
        table[i][35], table[i][36], table[i][37], table[i][38], table[i][39],
        table[i][40], table[i][41], table[i][42], table[i][43], table[i][44],
        table[i][45], table[i][46], table[i][47], table[i][48], table[i][49],
        table[i][50], table[i][51], table[i][52], table[i][53], table[i][54],
        table[i][55], table[i][56], table[i][57], table[i][58], table[i][59],
        table[i][60], table[i][61], table[i][62], table[i][63], table[i][64],
        table[i][65], table[i][66], table[i][67], table[i][68], table[i][69],
        table[i][70], table[i][71], table[i][72], table[i][73], table[i][74],
        table[i][75], table[i][76], table[i][77], table[i][78], table[i][79],
        table[i][80], table[i][81], table[i][82], table[i][83], table[i][84],
        table[i][85], table[i][86], table[i][87], table[i][88], table[i][89],
        table[i][90], table[i][91], table[i][92], table[i][93], table[i][94],
        table[i][95], table[i][96], table[i][97], table[i][98], table[i][99],
        table[i][100], table[i][101], table[i][102], table[i][103],
        table[i][104], table[i][105], table[i][106], table[i][107],
        table[i][108], table[i][109], table[i][110], table[i][111],
        table[i][112], table[i][113], table[i][114], table[i][115],
        table[i][116], table[i][117], table[i][118], table[i][119],
        table[i][120], table[i][121], table[i][122], table[i][123],
        table[i][124], table[i][125], table[i][126], table[i][127],
        table[i][128], table[i][129], table[i][130], table[i][131],
        table[i][132], table[i][133], table[i][134], table[i][135],
        table[i][136], table[i][137], table[i][138], table[i][139],
        table[i][140], table[i][141], table[i][142], table[i][143],
        table[i][144], table[i][145], table[i][146], table[i][147],
        table[i][148], table[i][149], table[i][150], table[i][151],
        table[i][152], table[i][153], table[i][154], table[i][155],
        table[i][156], table[i][157], table[i][158], table[i][159],
        table[i][160], table[i][161], table[i][162], table[i][163],
        table[i][164], table[i][165], table[i][166], table[i][167],
        table[i][168], table[i][169], table[i][170], table[i][171],
        table[i][172], table[i][173], table[i][174], table[i][175],
        table[i][176], table[i][177], table[i][178], table[i][179],
        table[i][180], table[i][181], table[i][182], table[i][183],
        table[i][184], table[i][185], table[i][186], table[i][187],
        table[i][188], table[i][189], table[i][190], table[i][191],
        table[i][192], table[i][193], table[i][194], table[i][195],
        table[i][196], table[i][197], table[i][198], table[i][199],
        table[i][200], table[i][201], table[i][202], table[i][203],
        table[i][204], table[i][205], table[i][206], table[i][207],
        table[i][208], table[i][209], table[i][210], table[i][211],
        table[i][212], table[i][213], table[i][214], table[i][215],
        table[i][216], table[i][217], table[i][218], table[i][219],
        table[i][220], table[i][221], table[i][222], table[i][223],
        table[i][224], table[i][225], table[i][226], table[i][227],
        table[i][228], table[i][229], table[i][230], table[i][231],
        table[i][232], table[i][233], table[i][234], table[i][235],
        table[i][236], table[i][237], table[i][238], table[i][239],
        table[i][240], table[i][241], table[i][242], table[i][243],
        table[i][244], table[i][245], table[i][246], table[i][247],
        table[i][248], table[i][249], table[i][250], table[i][251],
        table[i][252], table[i][253], table[i][254], table[i][255],
        table[i][256], table[i][257], table[i][258], table[i][259],
        table[i][260], table[i][261], table[i][262], table[i][263],
        table[i][264], table[i][265], table[i][266], table[i][267],
        table[i][268], table[i][269], table[i][270], table[i][271],
        table[i][272], table[i][273], table[i][274], table[i][275],
        table[i][276], table[i][277], table[i][278], table[i][279],
        table[i][280], table[i][281], table[i][282], table[i][283],
        table[i][284], table[i][285], table[i][286], table[i][287],
        table[i][288], table[i][289], table[i][290], table[i][291],
        table[i][292], table[i][293], table[i][294], table[i][295],
        table[i][296], table[i][297], table[i][298], table[i][299],
        table[i][300], table[i][301], table[i][302], table[i][303],
        table[i][304], table[i][305], table[i][306], table[i][307],
        table[i][308], table[i][309], table[i][310], table[i][311],
        table[i][312], table[i][313], table[i][314], table[i][315],
        table[i][316], table[i][317], table[i][318], table[i][319],
        table[i][320], table[i][321], table[i][322], table[i][323],
        table[i][324], table[i][325], table[i][326], table[i][327],
        table[i][328], table[i][329], table[i][330], table[i][331],
        table[i][332], table[i][333], table[i][334], table[i][335],
        table[i][336], table[i][337], table[i][338], table[i][339],
        table[i][340], table[i][341], table[i][342], table[i][343],
        table[i][344], table[i][345], table[i][346], table[i][347],
        table[i][348], table[i][349], table[i][350], table[i][351],
        table[i][352], table[i][353], table[i][354], table[i][355],
        table[i][356], table[i][357], table[i][358], table[i][359],
        table[i][360], table[i][361], table[i][362], table[i][363],
        table[i][364], table[i][365], table[i][366], table[i][367],
        table[i][368], table[i][369], table[i][370], table[i][371],
        table[i][372], table[i][373], table[i][374], table[i][375],
        table[i][376], table[i][377], table[i][378], table[i][379],
        table[i][380], table[i][381], table[i][382], table[i][383],
        table[i][384], table[i][385], table[i][386], table[i][387],
        table[i][388], table[i][389], table[i][390], table[i][391],
        table[i][392], table[i][393], table[i][394], table[i][395],
        table[i][396], table[i][397], table[i][398], table[i][399],
        table[i][400], table[i][401], table[i][402], table[i][403],
        table[i][404], table[i][405], table[i][406], table[i][407],
        table[i][408], table[i][409], table[i][410], table[i][411],
        table[i][412], table[i][413], table[i][414], table[i][415],
        table[i][416], table[i][417], table[i][418], table[i][419],
        table[i][420], table[i][421], table[i][422], table[i][423],
        table[i][424], table[i][425], table[i][426], table[i][427],
        table[i][428], table[i][429], table[i][430], table[i][431],
        table[i][432], table[i][433], table[i][434], table[i][435],
        table[i][436], table[i][437], table[i][438], table[i][439],
        table[i][440], table[i][441], table[i][442], table[i][443],
        table[i][444], table[i][445], table[i][446], table[i][447],
        table[i][448], table[i][449], table[i][450], table[i][451],
        table[i][452], table[i][453], table[i][454], table[i][455],
        table[i][456], table[i][457], table[i][458], table[i][459],
        table[i][460], table[i][461], table[i][462], table[i][463],
        table[i][464], table[i][465], table[i][466], table[i][467],
        table[i][468], table[i][469], table[i][470], table[i][471],
        table[i][472], table[i][473], table[i][474], table[i][475],
        table[i][476], table[i][477], table[i][478], table[i][479],
        table[i][480], table[i][481], table[i][482], table[i][483],
        table[i][484], table[i][485], table[i][486], table[i][487],
        table[i][488], table[i][489], table[i][490], table[i][491],
        table[i][492], table[i][493], table[i][494], table[i][495],
        table[i][496], table[i][497], table[i][498], table[i][499],
		table[i][0],
        table[i][1], table[i][2], table[i][3], table[i][4], table[i][5],
        table[i][6], table[i][7], table[i][8], table[i][9], table[i][10],
        table[i][11], table[i][12], table[i][13], table[i][14], table[i][15],
        table[i][16], table[i][17], table[i][18], table[i][19], table[i][20],
        table[i][21], table[i][22], table[i][23], table[i][24], table[i][25],
        table[i][26], table[i][27], table[i][28], table[i][29], table[i][30],
        table[i][31], table[i][32], table[i][33], table[i][34], table[i][35],
        table[i][36], table[i][37], table[i][38], table[i][39], table[i][40],
        table[i][41], table[i][42], table[i][43], table[i][44], table[i][45],
        table[i][46], table[i][47], table[i][48], table[i][49], table[i][50],
        table[i][51], table[i][52], table[i][53], table[i][54], table[i][55],
        table[i][56], table[i][57], table[i][58], table[i][59], table[i][60],
        table[i][61], table[i][62], table[i][63], table[i][64], table[i][65],
        table[i][66], table[i][67], table[i][68], table[i][69], table[i][70],
        table[i][71], table[i][72], table[i][73], table[i][74], table[i][75],
        table[i][76], table[i][77], table[i][78], table[i][79], table[i][80],
        table[i][81], table[i][82], table[i][83], table[i][84], table[i][85],
        table[i][86], table[i][87], table[i][88], table[i][89], table[i][90],
        table[i][91], table[i][92], table[i][93], table[i][94], table[i][95],
        table[i][96], table[i][97], table[i][98], table[i][99], table[i][100],
        table[i][101], table[i][102], table[i][103], table[i][104],
        table[i][105], table[i][106], table[i][107], table[i][108],
        table[i][109], table[i][110], table[i][111], table[i][112],
        table[i][113], table[i][114], table[i][115], table[i][116],
        table[i][117], table[i][118], table[i][119], table[i][120],
        table[i][121], table[i][122], table[i][123], table[i][124],
        table[i][125], table[i][126], table[i][127], table[i][128],
        table[i][129], table[i][130], table[i][131], table[i][132],
        table[i][133], table[i][134], table[i][135], table[i][136],
        table[i][137], table[i][138], table[i][139], table[i][140],
        table[i][141], table[i][142], table[i][143], table[i][144],
        table[i][145], table[i][146], table[i][147], table[i][148],
        table[i][149], table[i][150], table[i][151], table[i][152],
        table[i][153], table[i][154], table[i][155], table[i][156],
        table[i][157], table[i][158], table[i][159], table[i][160],
        table[i][161], table[i][162], table[i][163], table[i][164],
        table[i][165], table[i][166], table[i][167], table[i][168],
        table[i][169], table[i][170], table[i][171], table[i][172],
        table[i][173], table[i][174], table[i][175], table[i][176],
        table[i][177], table[i][178], table[i][179], table[i][180],
        table[i][181], table[i][182], table[i][183], table[i][184],
        table[i][185], table[i][186], table[i][187], table[i][188],
        table[i][189], table[i][190], table[i][191], table[i][192],
        table[i][193], table[i][194], table[i][195], table[i][196],
        table[i][197], table[i][198], table[i][199], table[i][200],
        table[i][201], table[i][202], table[i][203], table[i][204],
        table[i][205], table[i][206], table[i][207], table[i][208],
        table[i][209], table[i][210], table[i][211], table[i][212],
        table[i][213], table[i][214], table[i][215], table[i][216],
        table[i][217], table[i][218], table[i][219], table[i][220],
        table[i][221], table[i][222], table[i][223], table[i][224],
        table[i][225], table[i][226], table[i][227], table[i][228],
        table[i][229], table[i][230], table[i][231], table[i][232],
        table[i][233], table[i][234], table[i][235], table[i][236],
        table[i][237], table[i][238], table[i][239], table[i][240],
        table[i][241], table[i][242], table[i][243], table[i][244],
        table[i][245], table[i][246], table[i][247], table[i][248],
        table[i][249], table[i][250], table[i][251], table[i][252],
        table[i][253], table[i][254], table[i][255], table[i][256],
        table[i][257], table[i][258], table[i][259], table[i][260],
        table[i][261], table[i][262], table[i][263], table[i][264],
        table[i][265], table[i][266], table[i][267], table[i][268],
        table[i][269], table[i][270], table[i][271], table[i][272],
        table[i][273], table[i][274], table[i][275], table[i][276],
        table[i][277], table[i][278], table[i][279], table[i][280],
        table[i][281], table[i][282], table[i][283], table[i][284],
        table[i][285], table[i][286], table[i][287], table[i][288],
        table[i][289], table[i][290], table[i][291], table[i][292],
        table[i][293], table[i][294], table[i][295], table[i][296],
        table[i][297], table[i][298], table[i][299], table[i][300],
        table[i][301], table[i][302], table[i][303], table[i][304],
        table[i][305], table[i][306], table[i][307], table[i][308],
        table[i][309], table[i][310], table[i][311], table[i][312],
        table[i][313], table[i][314], table[i][315], table[i][316],
        table[i][317], table[i][318], table[i][319], table[i][320],
        table[i][321], table[i][322], table[i][323], table[i][324],
        table[i][325], table[i][326], table[i][327], table[i][328],
        table[i][329], table[i][330], table[i][331], table[i][332],
        table[i][333], table[i][334], table[i][335], table[i][336],
        table[i][337], table[i][338], table[i][339], table[i][340],
        table[i][341], table[i][342], table[i][343], table[i][344],
        table[i][345], table[i][346], table[i][347], table[i][348],
        table[i][349], table[i][350], table[i][351], table[i][352],
        table[i][353], table[i][354], table[i][355], table[i][356],
        table[i][357], table[i][358], table[i][359], table[i][360],
        table[i][361], table[i][362], table[i][363], table[i][364],
        table[i][365], table[i][366], table[i][367], table[i][368],
        table[i][369], table[i][370], table[i][371], table[i][372],
        table[i][373], table[i][374], table[i][375], table[i][376],
        table[i][377], table[i][378], table[i][379], table[i][380],
        table[i][381], table[i][382], table[i][383], table[i][384],
        table[i][385], table[i][386], table[i][387], table[i][388],
        table[i][389], table[i][390], table[i][391], table[i][392],
        table[i][393], table[i][394], table[i][395], table[i][396],
        table[i][397], table[i][398], table[i][399], table[i][400],
        table[i][401], table[i][402], table[i][403], table[i][404],
        table[i][405], table[i][406], table[i][407], table[i][408],
        table[i][409], table[i][410], table[i][411], table[i][412],
        table[i][413], table[i][414], table[i][415], table[i][416],
        table[i][417], table[i][418], table[i][419], table[i][420],
        table[i][421], table[i][422], table[i][423], table[i][424],
        table[i][425], table[i][426], table[i][427], table[i][428],
        table[i][429], table[i][430], table[i][431], table[i][432],
        table[i][433], table[i][434], table[i][435], table[i][436],
        table[i][437], table[i][438], table[i][439], table[i][440],
        table[i][441], table[i][442], table[i][443], table[i][444],
        table[i][445], table[i][446], table[i][447], table[i][448],
        table[i][449], table[i][450], table[i][451], table[i][452],
        table[i][453], table[i][454], table[i][455], table[i][456],
        table[i][457], table[i][458], table[i][459], table[i][460],
        table[i][461], table[i][462], table[i][463], table[i][464],
        table[i][465], table[i][466], table[i][467], table[i][468],
        table[i][469], table[i][470], table[i][471], table[i][472],
        table[i][473], table[i][474], table[i][475], table[i][476],
        table[i][477], table[i][478], table[i][479], table[i][480],
        table[i][481], table[i][482], table[i][483], table[i][484],
        table[i][485], table[i][486], table[i][487], table[i][488],
        table[i][489], table[i][490], table[i][491], table[i][492],
        table[i][493], table[i][494], table[i][495], table[i][496],
        table[i][497], table[i][498], table[i][499]);
}

void build_memtest1000_string(int i, int **table, char *command) {
    sprintf(
        command,
        "valgrind -q ./push_swap "
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | "
		"./checker_linux "
		"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][20], table[i][21], table[i][22], table[i][23], table[i][24],
        table[i][25], table[i][26], table[i][27], table[i][28], table[i][29],
        table[i][30], table[i][31], table[i][32], table[i][33], table[i][34],
        table[i][35], table[i][36], table[i][37], table[i][38], table[i][39],
        table[i][40], table[i][41], table[i][42], table[i][43], table[i][44],
        table[i][45], table[i][46], table[i][47], table[i][48], table[i][49],
        table[i][50], table[i][51], table[i][52], table[i][53], table[i][54],
        table[i][55], table[i][56], table[i][57], table[i][58], table[i][59],
        table[i][60], table[i][61], table[i][62], table[i][63], table[i][64],
        table[i][65], table[i][66], table[i][67], table[i][68], table[i][69],
        table[i][70], table[i][71], table[i][72], table[i][73], table[i][74],
        table[i][75], table[i][76], table[i][77], table[i][78], table[i][79],
        table[i][80], table[i][81], table[i][82], table[i][83], table[i][84],
        table[i][85], table[i][86], table[i][87], table[i][88], table[i][89],
        table[i][90], table[i][91], table[i][92], table[i][93], table[i][94],
        table[i][95], table[i][96], table[i][97], table[i][98], table[i][99],
        table[i][100], table[i][101], table[i][102], table[i][103],
        table[i][104], table[i][105], table[i][106], table[i][107],
        table[i][108], table[i][109], table[i][110], table[i][111],
        table[i][112], table[i][113], table[i][114], table[i][115],
        table[i][116], table[i][117], table[i][118], table[i][119],
        table[i][120], table[i][121], table[i][122], table[i][123],
        table[i][124], table[i][125], table[i][126], table[i][127],
        table[i][128], table[i][129], table[i][130], table[i][131],
        table[i][132], table[i][133], table[i][134], table[i][135],
        table[i][136], table[i][137], table[i][138], table[i][139],
        table[i][140], table[i][141], table[i][142], table[i][143],
        table[i][144], table[i][145], table[i][146], table[i][147],
        table[i][148], table[i][149], table[i][150], table[i][151],
        table[i][152], table[i][153], table[i][154], table[i][155],
        table[i][156], table[i][157], table[i][158], table[i][159],
        table[i][160], table[i][161], table[i][162], table[i][163],
        table[i][164], table[i][165], table[i][166], table[i][167],
        table[i][168], table[i][169], table[i][170], table[i][171],
        table[i][172], table[i][173], table[i][174], table[i][175],
        table[i][176], table[i][177], table[i][178], table[i][179],
        table[i][180], table[i][181], table[i][182], table[i][183],
        table[i][184], table[i][185], table[i][186], table[i][187],
        table[i][188], table[i][189], table[i][190], table[i][191],
        table[i][192], table[i][193], table[i][194], table[i][195],
        table[i][196], table[i][197], table[i][198], table[i][199],
        table[i][200], table[i][201], table[i][202], table[i][203],
        table[i][204], table[i][205], table[i][206], table[i][207],
        table[i][208], table[i][209], table[i][210], table[i][211],
        table[i][212], table[i][213], table[i][214], table[i][215],
        table[i][216], table[i][217], table[i][218], table[i][219],
        table[i][220], table[i][221], table[i][222], table[i][223],
        table[i][224], table[i][225], table[i][226], table[i][227],
        table[i][228], table[i][229], table[i][230], table[i][231],
        table[i][232], table[i][233], table[i][234], table[i][235],
        table[i][236], table[i][237], table[i][238], table[i][239],
        table[i][240], table[i][241], table[i][242], table[i][243],
        table[i][244], table[i][245], table[i][246], table[i][247],
        table[i][248], table[i][249], table[i][250], table[i][251],
        table[i][252], table[i][253], table[i][254], table[i][255],
        table[i][256], table[i][257], table[i][258], table[i][259],
        table[i][260], table[i][261], table[i][262], table[i][263],
        table[i][264], table[i][265], table[i][266], table[i][267],
        table[i][268], table[i][269], table[i][270], table[i][271],
        table[i][272], table[i][273], table[i][274], table[i][275],
        table[i][276], table[i][277], table[i][278], table[i][279],
        table[i][280], table[i][281], table[i][282], table[i][283],
        table[i][284], table[i][285], table[i][286], table[i][287],
        table[i][288], table[i][289], table[i][290], table[i][291],
        table[i][292], table[i][293], table[i][294], table[i][295],
        table[i][296], table[i][297], table[i][298], table[i][299],
        table[i][300], table[i][301], table[i][302], table[i][303],
        table[i][304], table[i][305], table[i][306], table[i][307],
        table[i][308], table[i][309], table[i][310], table[i][311],
        table[i][312], table[i][313], table[i][314], table[i][315],
        table[i][316], table[i][317], table[i][318], table[i][319],
        table[i][320], table[i][321], table[i][322], table[i][323],
        table[i][324], table[i][325], table[i][326], table[i][327],
        table[i][328], table[i][329], table[i][330], table[i][331],
        table[i][332], table[i][333], table[i][334], table[i][335],
        table[i][336], table[i][337], table[i][338], table[i][339],
        table[i][340], table[i][341], table[i][342], table[i][343],
        table[i][344], table[i][345], table[i][346], table[i][347],
        table[i][348], table[i][349], table[i][350], table[i][351],
        table[i][352], table[i][353], table[i][354], table[i][355],
        table[i][356], table[i][357], table[i][358], table[i][359],
        table[i][360], table[i][361], table[i][362], table[i][363],
        table[i][364], table[i][365], table[i][366], table[i][367],
        table[i][368], table[i][369], table[i][370], table[i][371],
        table[i][372], table[i][373], table[i][374], table[i][375],
        table[i][376], table[i][377], table[i][378], table[i][379],
        table[i][380], table[i][381], table[i][382], table[i][383],
        table[i][384], table[i][385], table[i][386], table[i][387],
        table[i][388], table[i][389], table[i][390], table[i][391],
        table[i][392], table[i][393], table[i][394], table[i][395],
        table[i][396], table[i][397], table[i][398], table[i][399],
        table[i][400], table[i][401], table[i][402], table[i][403],
        table[i][404], table[i][405], table[i][406], table[i][407],
        table[i][408], table[i][409], table[i][410], table[i][411],
        table[i][412], table[i][413], table[i][414], table[i][415],
        table[i][416], table[i][417], table[i][418], table[i][419],
        table[i][420], table[i][421], table[i][422], table[i][423],
        table[i][424], table[i][425], table[i][426], table[i][427],
        table[i][428], table[i][429], table[i][430], table[i][431],
        table[i][432], table[i][433], table[i][434], table[i][435],
        table[i][436], table[i][437], table[i][438], table[i][439],
        table[i][440], table[i][441], table[i][442], table[i][443],
        table[i][444], table[i][445], table[i][446], table[i][447],
        table[i][448], table[i][449], table[i][450], table[i][451],
        table[i][452], table[i][453], table[i][454], table[i][455],
        table[i][456], table[i][457], table[i][458], table[i][459],
        table[i][460], table[i][461], table[i][462], table[i][463],
        table[i][464], table[i][465], table[i][466], table[i][467],
        table[i][468], table[i][469], table[i][470], table[i][471],
        table[i][472], table[i][473], table[i][474], table[i][475],
        table[i][476], table[i][477], table[i][478], table[i][479],
        table[i][480], table[i][481], table[i][482], table[i][483],
        table[i][484], table[i][485], table[i][486], table[i][487],
        table[i][488], table[i][489], table[i][490], table[i][491],
        table[i][492], table[i][493], table[i][494], table[i][495],
        table[i][496], table[i][497], table[i][498], table[i][499],
        table[i][500], table[i][501], table[i][502], table[i][503],
        table[i][504], table[i][505], table[i][506], table[i][507],
        table[i][508], table[i][509], table[i][510], table[i][511],
        table[i][512], table[i][513], table[i][514], table[i][515],
        table[i][516], table[i][517], table[i][518], table[i][519],
        table[i][520], table[i][521], table[i][522], table[i][523],
        table[i][524], table[i][525], table[i][526], table[i][527],
        table[i][528], table[i][529], table[i][530], table[i][531],
        table[i][532], table[i][533], table[i][534], table[i][535],
        table[i][536], table[i][537], table[i][538], table[i][539],
        table[i][540], table[i][541], table[i][542], table[i][543],
        table[i][544], table[i][545], table[i][546], table[i][547],
        table[i][548], table[i][549], table[i][550], table[i][551],
        table[i][552], table[i][553], table[i][554], table[i][555],
        table[i][556], table[i][557], table[i][558], table[i][559],
        table[i][560], table[i][561], table[i][562], table[i][563],
        table[i][564], table[i][565], table[i][566], table[i][567],
        table[i][568], table[i][569], table[i][570], table[i][571],
        table[i][572], table[i][573], table[i][574], table[i][575],
        table[i][576], table[i][577], table[i][578], table[i][579],
        table[i][580], table[i][581], table[i][582], table[i][583],
        table[i][584], table[i][585], table[i][586], table[i][587],
        table[i][588], table[i][589], table[i][590], table[i][591],
        table[i][592], table[i][593], table[i][594], table[i][595],
        table[i][596], table[i][597], table[i][598], table[i][599],
        table[i][600], table[i][601], table[i][602], table[i][603],
        table[i][604], table[i][605], table[i][606], table[i][607],
        table[i][608], table[i][609], table[i][610], table[i][611],
        table[i][612], table[i][613], table[i][614], table[i][615],
        table[i][616], table[i][617], table[i][618], table[i][619],
        table[i][620], table[i][621], table[i][622], table[i][623],
        table[i][624], table[i][625], table[i][626], table[i][627],
        table[i][628], table[i][629], table[i][630], table[i][631],
        table[i][632], table[i][633], table[i][634], table[i][635],
        table[i][636], table[i][637], table[i][638], table[i][639],
        table[i][640], table[i][641], table[i][642], table[i][643],
        table[i][644], table[i][645], table[i][646], table[i][647],
        table[i][648], table[i][649], table[i][650], table[i][651],
        table[i][652], table[i][653], table[i][654], table[i][655],
        table[i][656], table[i][657], table[i][658], table[i][659],
        table[i][660], table[i][661], table[i][662], table[i][663],
        table[i][664], table[i][665], table[i][666], table[i][667],
        table[i][668], table[i][669], table[i][670], table[i][671],
        table[i][672], table[i][673], table[i][674], table[i][675],
        table[i][676], table[i][677], table[i][678], table[i][679],
        table[i][680], table[i][681], table[i][682], table[i][683],
        table[i][684], table[i][685], table[i][686], table[i][687],
        table[i][688], table[i][689], table[i][690], table[i][691],
        table[i][692], table[i][693], table[i][694], table[i][695],
        table[i][696], table[i][697], table[i][698], table[i][699],
        table[i][700], table[i][701], table[i][702], table[i][703],
        table[i][704], table[i][705], table[i][706], table[i][707],
        table[i][708], table[i][709], table[i][710], table[i][711],
        table[i][712], table[i][713], table[i][714], table[i][715],
        table[i][716], table[i][717], table[i][718], table[i][719],
        table[i][720], table[i][721], table[i][722], table[i][723],
        table[i][724], table[i][725], table[i][726], table[i][727],
        table[i][728], table[i][729], table[i][730], table[i][731],
        table[i][732], table[i][733], table[i][734], table[i][735],
        table[i][736], table[i][737], table[i][738], table[i][739],
        table[i][740], table[i][741], table[i][742], table[i][743],
        table[i][744], table[i][745], table[i][746], table[i][747],
        table[i][748], table[i][749], table[i][750], table[i][751],
        table[i][752], table[i][753], table[i][754], table[i][755],
        table[i][756], table[i][757], table[i][758], table[i][759],
        table[i][760], table[i][761], table[i][762], table[i][763],
        table[i][764], table[i][765], table[i][766], table[i][767],
        table[i][768], table[i][769], table[i][770], table[i][771],
        table[i][772], table[i][773], table[i][774], table[i][775],
        table[i][776], table[i][777], table[i][778], table[i][779],
        table[i][780], table[i][781], table[i][782], table[i][783],
        table[i][784], table[i][785], table[i][786], table[i][787],
        table[i][788], table[i][789], table[i][790], table[i][791],
        table[i][792], table[i][793], table[i][794], table[i][795],
        table[i][796], table[i][797], table[i][798], table[i][799],
        table[i][800], table[i][801], table[i][802], table[i][803],
        table[i][804], table[i][805], table[i][806], table[i][807],
        table[i][808], table[i][809], table[i][810], table[i][811],
        table[i][812], table[i][813], table[i][814], table[i][815],
        table[i][816], table[i][817], table[i][818], table[i][819],
        table[i][820], table[i][821], table[i][822], table[i][823],
        table[i][824], table[i][825], table[i][826], table[i][827],
        table[i][828], table[i][829], table[i][830], table[i][831],
        table[i][832], table[i][833], table[i][834], table[i][835],
        table[i][836], table[i][837], table[i][838], table[i][839],
        table[i][840], table[i][841], table[i][842], table[i][843],
        table[i][844], table[i][845], table[i][846], table[i][847],
        table[i][848], table[i][849], table[i][850], table[i][851],
        table[i][852], table[i][853], table[i][854], table[i][855],
        table[i][856], table[i][857], table[i][858], table[i][859],
        table[i][860], table[i][861], table[i][862], table[i][863],
        table[i][864], table[i][865], table[i][866], table[i][867],
        table[i][868], table[i][869], table[i][870], table[i][871],
        table[i][872], table[i][873], table[i][874], table[i][875],
        table[i][876], table[i][877], table[i][878], table[i][879],
        table[i][880], table[i][881], table[i][882], table[i][883],
        table[i][884], table[i][885], table[i][886], table[i][887],
        table[i][888], table[i][889], table[i][890], table[i][891],
        table[i][892], table[i][893], table[i][894], table[i][895],
        table[i][896], table[i][897], table[i][898], table[i][899],
        table[i][900], table[i][901], table[i][902], table[i][903],
        table[i][904], table[i][905], table[i][906], table[i][907],
        table[i][908], table[i][909], table[i][910], table[i][911],
        table[i][912], table[i][913], table[i][914], table[i][915],
        table[i][916], table[i][917], table[i][918], table[i][919],
        table[i][920], table[i][921], table[i][922], table[i][923],
        table[i][924], table[i][925], table[i][926], table[i][927],
        table[i][928], table[i][929], table[i][930], table[i][931],
        table[i][932], table[i][933], table[i][934], table[i][935],
        table[i][936], table[i][937], table[i][938], table[i][939],
        table[i][940], table[i][941], table[i][942], table[i][943],
        table[i][944], table[i][945], table[i][946], table[i][947],
        table[i][948], table[i][949], table[i][950], table[i][951],
        table[i][952], table[i][953], table[i][954], table[i][955],
        table[i][956], table[i][957], table[i][958], table[i][959],
        table[i][960], table[i][961], table[i][962], table[i][963],
        table[i][964], table[i][965], table[i][966], table[i][967],
        table[i][968], table[i][969], table[i][970], table[i][971],
        table[i][972], table[i][973], table[i][974], table[i][975],
        table[i][976], table[i][977], table[i][978], table[i][979],
        table[i][980], table[i][981], table[i][982], table[i][983],
        table[i][984], table[i][985], table[i][986], table[i][987],
        table[i][988], table[i][989], table[i][990], table[i][991],
        table[i][992], table[i][993], table[i][994], table[i][995],
        table[i][996], table[i][997], table[i][998], table[i][999], table[i][0],
        table[i][1], table[i][2], table[i][3], table[i][4], table[i][5],
        table[i][6], table[i][7], table[i][8], table[i][9], table[i][10],
        table[i][11], table[i][12], table[i][13], table[i][14], table[i][15],
        table[i][16], table[i][17], table[i][18], table[i][19], table[i][20],
        table[i][21], table[i][22], table[i][23], table[i][24], table[i][25],
        table[i][26], table[i][27], table[i][28], table[i][29], table[i][30],
        table[i][31], table[i][32], table[i][33], table[i][34], table[i][35],
        table[i][36], table[i][37], table[i][38], table[i][39], table[i][40],
        table[i][41], table[i][42], table[i][43], table[i][44], table[i][45],
        table[i][46], table[i][47], table[i][48], table[i][49], table[i][50],
        table[i][51], table[i][52], table[i][53], table[i][54], table[i][55],
        table[i][56], table[i][57], table[i][58], table[i][59], table[i][60],
        table[i][61], table[i][62], table[i][63], table[i][64], table[i][65],
        table[i][66], table[i][67], table[i][68], table[i][69], table[i][70],
        table[i][71], table[i][72], table[i][73], table[i][74], table[i][75],
        table[i][76], table[i][77], table[i][78], table[i][79], table[i][80],
        table[i][81], table[i][82], table[i][83], table[i][84], table[i][85],
        table[i][86], table[i][87], table[i][88], table[i][89], table[i][90],
        table[i][91], table[i][92], table[i][93], table[i][94], table[i][95],
        table[i][96], table[i][97], table[i][98], table[i][99], table[i][100],
        table[i][101], table[i][102], table[i][103], table[i][104],
        table[i][105], table[i][106], table[i][107], table[i][108],
        table[i][109], table[i][110], table[i][111], table[i][112],
        table[i][113], table[i][114], table[i][115], table[i][116],
        table[i][117], table[i][118], table[i][119], table[i][120],
        table[i][121], table[i][122], table[i][123], table[i][124],
        table[i][125], table[i][126], table[i][127], table[i][128],
        table[i][129], table[i][130], table[i][131], table[i][132],
        table[i][133], table[i][134], table[i][135], table[i][136],
        table[i][137], table[i][138], table[i][139], table[i][140],
        table[i][141], table[i][142], table[i][143], table[i][144],
        table[i][145], table[i][146], table[i][147], table[i][148],
        table[i][149], table[i][150], table[i][151], table[i][152],
        table[i][153], table[i][154], table[i][155], table[i][156],
        table[i][157], table[i][158], table[i][159], table[i][160],
        table[i][161], table[i][162], table[i][163], table[i][164],
        table[i][165], table[i][166], table[i][167], table[i][168],
        table[i][169], table[i][170], table[i][171], table[i][172],
        table[i][173], table[i][174], table[i][175], table[i][176],
        table[i][177], table[i][178], table[i][179], table[i][180],
        table[i][181], table[i][182], table[i][183], table[i][184],
        table[i][185], table[i][186], table[i][187], table[i][188],
        table[i][189], table[i][190], table[i][191], table[i][192],
        table[i][193], table[i][194], table[i][195], table[i][196],
        table[i][197], table[i][198], table[i][199], table[i][200],
        table[i][201], table[i][202], table[i][203], table[i][204],
        table[i][205], table[i][206], table[i][207], table[i][208],
        table[i][209], table[i][210], table[i][211], table[i][212],
        table[i][213], table[i][214], table[i][215], table[i][216],
        table[i][217], table[i][218], table[i][219], table[i][220],
        table[i][221], table[i][222], table[i][223], table[i][224],
        table[i][225], table[i][226], table[i][227], table[i][228],
        table[i][229], table[i][230], table[i][231], table[i][232],
        table[i][233], table[i][234], table[i][235], table[i][236],
        table[i][237], table[i][238], table[i][239], table[i][240],
        table[i][241], table[i][242], table[i][243], table[i][244],
        table[i][245], table[i][246], table[i][247], table[i][248],
        table[i][249], table[i][250], table[i][251], table[i][252],
        table[i][253], table[i][254], table[i][255], table[i][256],
        table[i][257], table[i][258], table[i][259], table[i][260],
        table[i][261], table[i][262], table[i][263], table[i][264],
        table[i][265], table[i][266], table[i][267], table[i][268],
        table[i][269], table[i][270], table[i][271], table[i][272],
        table[i][273], table[i][274], table[i][275], table[i][276],
        table[i][277], table[i][278], table[i][279], table[i][280],
        table[i][281], table[i][282], table[i][283], table[i][284],
        table[i][285], table[i][286], table[i][287], table[i][288],
        table[i][289], table[i][290], table[i][291], table[i][292],
        table[i][293], table[i][294], table[i][295], table[i][296],
        table[i][297], table[i][298], table[i][299], table[i][300],
        table[i][301], table[i][302], table[i][303], table[i][304],
        table[i][305], table[i][306], table[i][307], table[i][308],
        table[i][309], table[i][310], table[i][311], table[i][312],
        table[i][313], table[i][314], table[i][315], table[i][316],
        table[i][317], table[i][318], table[i][319], table[i][320],
        table[i][321], table[i][322], table[i][323], table[i][324],
        table[i][325], table[i][326], table[i][327], table[i][328],
        table[i][329], table[i][330], table[i][331], table[i][332],
        table[i][333], table[i][334], table[i][335], table[i][336],
        table[i][337], table[i][338], table[i][339], table[i][340],
        table[i][341], table[i][342], table[i][343], table[i][344],
        table[i][345], table[i][346], table[i][347], table[i][348],
        table[i][349], table[i][350], table[i][351], table[i][352],
        table[i][353], table[i][354], table[i][355], table[i][356],
        table[i][357], table[i][358], table[i][359], table[i][360],
        table[i][361], table[i][362], table[i][363], table[i][364],
        table[i][365], table[i][366], table[i][367], table[i][368],
        table[i][369], table[i][370], table[i][371], table[i][372],
        table[i][373], table[i][374], table[i][375], table[i][376],
        table[i][377], table[i][378], table[i][379], table[i][380],
        table[i][381], table[i][382], table[i][383], table[i][384],
        table[i][385], table[i][386], table[i][387], table[i][388],
        table[i][389], table[i][390], table[i][391], table[i][392],
        table[i][393], table[i][394], table[i][395], table[i][396],
        table[i][397], table[i][398], table[i][399], table[i][400],
        table[i][401], table[i][402], table[i][403], table[i][404],
        table[i][405], table[i][406], table[i][407], table[i][408],
        table[i][409], table[i][410], table[i][411], table[i][412],
        table[i][413], table[i][414], table[i][415], table[i][416],
        table[i][417], table[i][418], table[i][419], table[i][420],
        table[i][421], table[i][422], table[i][423], table[i][424],
        table[i][425], table[i][426], table[i][427], table[i][428],
        table[i][429], table[i][430], table[i][431], table[i][432],
        table[i][433], table[i][434], table[i][435], table[i][436],
        table[i][437], table[i][438], table[i][439], table[i][440],
        table[i][441], table[i][442], table[i][443], table[i][444],
        table[i][445], table[i][446], table[i][447], table[i][448],
        table[i][449], table[i][450], table[i][451], table[i][452],
        table[i][453], table[i][454], table[i][455], table[i][456],
        table[i][457], table[i][458], table[i][459], table[i][460],
        table[i][461], table[i][462], table[i][463], table[i][464],
        table[i][465], table[i][466], table[i][467], table[i][468],
        table[i][469], table[i][470], table[i][471], table[i][472],
        table[i][473], table[i][474], table[i][475], table[i][476],
        table[i][477], table[i][478], table[i][479], table[i][480],
        table[i][481], table[i][482], table[i][483], table[i][484],
        table[i][485], table[i][486], table[i][487], table[i][488],
        table[i][489], table[i][490], table[i][491], table[i][492],
        table[i][493], table[i][494], table[i][495], table[i][496],
        table[i][497], table[i][498], table[i][499], table[i][500],
        table[i][501], table[i][502], table[i][503], table[i][504],
        table[i][505], table[i][506], table[i][507], table[i][508],
        table[i][509], table[i][510], table[i][511], table[i][512],
        table[i][513], table[i][514], table[i][515], table[i][516],
        table[i][517], table[i][518], table[i][519], table[i][520],
        table[i][521], table[i][522], table[i][523], table[i][524],
        table[i][525], table[i][526], table[i][527], table[i][528],
        table[i][529], table[i][530], table[i][531], table[i][532],
        table[i][533], table[i][534], table[i][535], table[i][536],
        table[i][537], table[i][538], table[i][539], table[i][540],
        table[i][541], table[i][542], table[i][543], table[i][544],
        table[i][545], table[i][546], table[i][547], table[i][548],
        table[i][549], table[i][550], table[i][551], table[i][552],
        table[i][553], table[i][554], table[i][555], table[i][556],
        table[i][557], table[i][558], table[i][559], table[i][560],
        table[i][561], table[i][562], table[i][563], table[i][564],
        table[i][565], table[i][566], table[i][567], table[i][568],
        table[i][569], table[i][570], table[i][571], table[i][572],
        table[i][573], table[i][574], table[i][575], table[i][576],
        table[i][577], table[i][578], table[i][579], table[i][580],
        table[i][581], table[i][582], table[i][583], table[i][584],
        table[i][585], table[i][586], table[i][587], table[i][588],
        table[i][589], table[i][590], table[i][591], table[i][592],
        table[i][593], table[i][594], table[i][595], table[i][596],
        table[i][597], table[i][598], table[i][599], table[i][600],
        table[i][601], table[i][602], table[i][603], table[i][604],
        table[i][605], table[i][606], table[i][607], table[i][608],
        table[i][609], table[i][610], table[i][611], table[i][612],
        table[i][613], table[i][614], table[i][615], table[i][616],
        table[i][617], table[i][618], table[i][619], table[i][620],
        table[i][621], table[i][622], table[i][623], table[i][624],
        table[i][625], table[i][626], table[i][627], table[i][628],
        table[i][629], table[i][630], table[i][631], table[i][632],
        table[i][633], table[i][634], table[i][635], table[i][636],
        table[i][637], table[i][638], table[i][639], table[i][640],
        table[i][641], table[i][642], table[i][643], table[i][644],
        table[i][645], table[i][646], table[i][647], table[i][648],
        table[i][649], table[i][650], table[i][651], table[i][652],
        table[i][653], table[i][654], table[i][655], table[i][656],
        table[i][657], table[i][658], table[i][659], table[i][660],
        table[i][661], table[i][662], table[i][663], table[i][664],
        table[i][665], table[i][666], table[i][667], table[i][668],
        table[i][669], table[i][670], table[i][671], table[i][672],
        table[i][673], table[i][674], table[i][675], table[i][676],
        table[i][677], table[i][678], table[i][679], table[i][680],
        table[i][681], table[i][682], table[i][683], table[i][684],
        table[i][685], table[i][686], table[i][687], table[i][688],
        table[i][689], table[i][690], table[i][691], table[i][692],
        table[i][693], table[i][694], table[i][695], table[i][696],
        table[i][697], table[i][698], table[i][699], table[i][700],
        table[i][701], table[i][702], table[i][703], table[i][704],
        table[i][705], table[i][706], table[i][707], table[i][708],
        table[i][709], table[i][710], table[i][711], table[i][712],
        table[i][713], table[i][714], table[i][715], table[i][716],
        table[i][717], table[i][718], table[i][719], table[i][720],
        table[i][721], table[i][722], table[i][723], table[i][724],
        table[i][725], table[i][726], table[i][727], table[i][728],
        table[i][729], table[i][730], table[i][731], table[i][732],
        table[i][733], table[i][734], table[i][735], table[i][736],
        table[i][737], table[i][738], table[i][739], table[i][740],
        table[i][741], table[i][742], table[i][743], table[i][744],
        table[i][745], table[i][746], table[i][747], table[i][748],
        table[i][749], table[i][750], table[i][751], table[i][752],
        table[i][753], table[i][754], table[i][755], table[i][756],
        table[i][757], table[i][758], table[i][759], table[i][760],
        table[i][761], table[i][762], table[i][763], table[i][764],
        table[i][765], table[i][766], table[i][767], table[i][768],
        table[i][769], table[i][770], table[i][771], table[i][772],
        table[i][773], table[i][774], table[i][775], table[i][776],
        table[i][777], table[i][778], table[i][779], table[i][780],
        table[i][781], table[i][782], table[i][783], table[i][784],
        table[i][785], table[i][786], table[i][787], table[i][788],
        table[i][789], table[i][790], table[i][791], table[i][792],
        table[i][793], table[i][794], table[i][795], table[i][796],
        table[i][797], table[i][798], table[i][799], table[i][800],
        table[i][801], table[i][802], table[i][803], table[i][804],
        table[i][805], table[i][806], table[i][807], table[i][808],
        table[i][809], table[i][810], table[i][811], table[i][812],
        table[i][813], table[i][814], table[i][815], table[i][816],
        table[i][817], table[i][818], table[i][819], table[i][820],
        table[i][821], table[i][822], table[i][823], table[i][824],
        table[i][825], table[i][826], table[i][827], table[i][828],
        table[i][829], table[i][830], table[i][831], table[i][832],
        table[i][833], table[i][834], table[i][835], table[i][836],
        table[i][837], table[i][838], table[i][839], table[i][840],
        table[i][841], table[i][842], table[i][843], table[i][844],
        table[i][845], table[i][846], table[i][847], table[i][848],
        table[i][849], table[i][850], table[i][851], table[i][852],
        table[i][853], table[i][854], table[i][855], table[i][856],
        table[i][857], table[i][858], table[i][859], table[i][860],
        table[i][861], table[i][862], table[i][863], table[i][864],
        table[i][865], table[i][866], table[i][867], table[i][868],
        table[i][869], table[i][870], table[i][871], table[i][872],
        table[i][873], table[i][874], table[i][875], table[i][876],
        table[i][877], table[i][878], table[i][879], table[i][880],
        table[i][881], table[i][882], table[i][883], table[i][884],
        table[i][885], table[i][886], table[i][887], table[i][888],
        table[i][889], table[i][890], table[i][891], table[i][892],
        table[i][893], table[i][894], table[i][895], table[i][896],
        table[i][897], table[i][898], table[i][899], table[i][900],
        table[i][901], table[i][902], table[i][903], table[i][904],
        table[i][905], table[i][906], table[i][907], table[i][908],
        table[i][909], table[i][910], table[i][911], table[i][912],
        table[i][913], table[i][914], table[i][915], table[i][916],
        table[i][917], table[i][918], table[i][919], table[i][920],
        table[i][921], table[i][922], table[i][923], table[i][924],
        table[i][925], table[i][926], table[i][927], table[i][928],
        table[i][929], table[i][930], table[i][931], table[i][932],
        table[i][933], table[i][934], table[i][935], table[i][936],
        table[i][937], table[i][938], table[i][939], table[i][940],
        table[i][941], table[i][942], table[i][943], table[i][944],
        table[i][945], table[i][946], table[i][947], table[i][948],
        table[i][949], table[i][950], table[i][951], table[i][952],
        table[i][953], table[i][954], table[i][955], table[i][956],
        table[i][957], table[i][958], table[i][959], table[i][960],
        table[i][961], table[i][962], table[i][963], table[i][964],
        table[i][965], table[i][966], table[i][967], table[i][968],
        table[i][969], table[i][970], table[i][971], table[i][972],
        table[i][973], table[i][974], table[i][975], table[i][976],
        table[i][977], table[i][978], table[i][979], table[i][980],
        table[i][981], table[i][982], table[i][983], table[i][984],
        table[i][985], table[i][986], table[i][987], table[i][988],
        table[i][989], table[i][990], table[i][991], table[i][992],
        table[i][993], table[i][994], table[i][995], table[i][996],
        table[i][997], table[i][998], table[i][999]);
}

void execute_memtest(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char buffer[10];
    FILE *output;
    int i = 0;
    //
    // while (table[i]) {
    //     char command[10000];
    //     build_memtest3_string(command, i, table);
    //     output = popen(command, "r");
    //     fgets(buffer, 10, output);
    //     printf("arr[%d]: { ", i);
    //     for (int j = 0; j < 3; j++) printf("%d ", table[i][j]);
    //     printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
    //     if (strncmp(buffer, "OK\n", 2) != 0) {
    //         printf("ERROR\n");
    //         exit(1);
    //     }
    //     pclose(output);
    //     i++;
    // }
    //
    // i += 2;
    // while (table[i]) {
    //     char command[10000];
    //     build_memtest5_string(command, i, table);
    //     output = popen(command, "r");
    //     fgets(buffer, 10, output);
    //     printf("arr[%d]: { ", i);
    //     for (int j = 0; j < 5; j++) printf("%d ", table[i][j]);
    //     printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
    //     if (strncmp(buffer, "OK\n", 2) != 0) {
    //         printf("ERROR\n");
    //         exit(1);
    //     }
    //     pclose(output);
    //     i++;
    // }
    //
    // i++;
    // while (table[i]) {
    //     char command[10000];
    //     build_memtest10_string(command, i, table);
    //     output = popen(command, "r");
    //     fgets(buffer, 10, output);
    //     printf("arr[%d]: { ", i);
    //     for (int j = 0; j < 10; j++) printf("%d ", table[i][j]);
    //     printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
    //     if (strncmp(buffer, "OK\n", 2) != 0) {
    //         printf("ERROR\n");
    //         exit(1);
    //     }
    //     pclose(output);
    //     i++;
    // }
    //
    // i = 15;
    // while (table[i]) {
    //     char command[10000];
    //     build_memtest15_string(command, i, table);
    //     output = popen(command, "r");
    //     fgets(buffer, 10, output);
    //     printf("arr[%d]: { ", i);
    //     for (int j = 0; j < 15; j++) printf("%d ", table[i][j]);
    //     printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
    //     if (strncmp(buffer, "OK\n", 2) != 0) {
    //         printf("ERROR\n");
    //         exit(1);
    //     }
    //     pclose(output);
    //     i++;
    // }
    //
    // i++;
    // while (table[i]) {
    //     char command[10000];
    //     build_memtest20_string(command, i, table);
    //     output = popen(command, "r");
    //     fgets(buffer, 10, output);
    //     printf("arr[%d]: { ", i);
    //     for (int j = 0; j < 20; j++) printf("%d ", table[i][j]);
    //     printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
    //     if (strncmp(buffer, "OK\n", 2) != 0) {
    //         printf("ERROR\n");
    //         exit(1);
    //     }
    //     pclose(output);
    //     i++;
    // }
    //
    // i = 27;
    // while (table[i]) {
    //     char command[10000];
    //     build_memtest100_string(i, table, command);
    //     output = popen(command, "r");
    //     fgets(buffer, 10, output);
    //     printf("arr[%d]: { ", i);
    //     for (int j = 0; j < 100; j++) printf("%d ", table[i][j]);
    //     printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
    //     if (strncmp(buffer, "OK\n", 2) != 0) {
    //         printf("ERROR\n");
    //         exit(1);
    //     }
    //     pclose(output);
    //     i++;
    // }
    //
    // i++;
    // while (table[i]) {
    //     char command[100000];
    //     build_memtest500_string(i, table, command);
    //     output = popen(command, "r");
    //     fgets(buffer, 10, output);
    //     printf("arr[%d]: { ", i);
    //     for (int j = 0; j < 500; j++) printf("%d ", table[i][j]);
    //     printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
    //     pclose(output);
    //     i++;
    // }

    i = 35;
	char *command = calloc(sizeof(char), 8000);
	build_memtest1000_string(i, table, command);
	output = popen(command, "r");
	printf("command: %s\n", command);
	fgets(buffer, 10, output);
	printf("arr[%d]: { ", i);
	for (int j = 0; j < 1000; j++) printf("%d ", table[i][j]);
	printf("} \nOfficial Sorting Instructions Checker: %s", buffer);
	pclose(output);
	free(command);
}

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_permutation_table();
    printf("\n\n\n		Running tests with valgrind -q \n\n\n\n");
    execute_memtest(args);
    ft_free_arr_size((void **)args->table, 100);
    free(args);
    printf(
        "\n\n\nIf you didnt see any valgrind messages it means no "
        "memory leaks were found in your program\n\n\n\n");
}
