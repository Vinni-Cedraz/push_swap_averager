#include "../include/averager.h"

static void print_message(char *reference, char *buffer);

void execute_bonus5(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[HUGE_CMD_LEN];
    char reference_cmd[HUGE_CMD_LEN];
    char buffer[BUF_LEN];
    char reference[BUF_LEN];
    FILE *output;
    FILE *reference_output;
    int i = 7;
    int arr_size = 5;

    printf(WHITE "\n\nBONUS RIGHT TESTS" DEF_COLOR);
    printf(HRED"\n		with valgrind -q \n\n" DEF_COLOR);
    while (table[i]) {
        build_bonus_string(command, arr_size, i, table);
        build_bonus_reference_string(reference_cmd, arr_size, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, BUF_LEN, output);
        fgets(reference, BUF_LEN, reference_output);
        printf(HBLUE "size(%d):" DEF_COLOR "{ ", arr_size);
        for (int j = 0; j < arr_size; j++)
            printf("%d ", table[i][j]);
        printf("}\n");
        print_message(reference, buffer);
        if (strcmp(buffer, reference) != 0) {
            printf(HRED "ERROR\n" DEF_COLOR);
            exit(1);
        }
        pclose(output);
        pclose(reference_output);
        i++;
    }
}

void execute_bonus10(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[HUGE_CMD_LEN];
    char reference_cmd[HUGE_CMD_LEN];
    char buffer[BUF_LEN];
    char reference[BUF_LEN];
    FILE *output;
    FILE *reference_output;
    int i = 11;
    int arr_size = 10;

    while (table[i]) {
        build_bonus_string(command, arr_size, i, table);
        build_bonus_reference_string(reference_cmd, arr_size, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, BUF_LEN, output);
        fgets(reference, BUF_LEN, reference_output);
        printf(HBLUE "size(%d):" DEF_COLOR "{ ", arr_size);
        for (int j = 0; j < arr_size; j++)
            printf("%d ", table[i][j]);
        printf("}\n");
        print_message(reference, buffer);
        if (strcmp(buffer, reference) != 0) {
            printf(HRED "ERROR\n" DEF_COLOR);
            exit(1);
        }
        pclose(output);
        pclose(reference_output);
        i++;
    }
}

void execute_bonus15(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[HUGE_CMD_LEN];
    char reference_cmd[HUGE_CMD_LEN];
    char buffer[BUF_LEN];
    char reference[BUF_LEN];
    FILE *output;
    FILE *reference_output;
    int i = 15;
    int arr_size = 15;

    while (table[i]) {
        build_bonus_string(command, arr_size, i, table);
        build_bonus_reference_string(reference_cmd, arr_size, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, BUF_LEN, output);
        fgets(reference, BUF_LEN, reference_output);
        printf(HBLUE "size(%d):" DEF_COLOR "{ ", arr_size);
        for (int j = 0; j < arr_size; j++)
            printf("%d ", table[i][j]);
        printf("}\n");
        print_message(reference, buffer);
        if (strcmp(buffer, reference) != 0) {
            printf(HRED "ERROR\n" DEF_COLOR);
            exit(1);
        }
        pclose(output);
        pclose(reference_output);
        i++;
    }
}

void execute_bonus20(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[HUGE_CMD_LEN];
    char reference_cmd[HUGE_CMD_LEN];
    char buffer[BUF_LEN];
    char reference[BUF_LEN];
    FILE *output;
    FILE *reference_output;
    int i = 19;
    int arr_size = 20;

    while (table[i]) {
        build_bonus_string(command, arr_size, i, table);
        build_bonus_reference_string(reference_cmd, arr_size, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, BUF_LEN, output);
        fgets(reference, BUF_LEN, reference_output);
        printf(HBLUE "size(%d):" DEF_COLOR "{ ", arr_size);
        for (int j = 0; j < arr_size; j++)
            printf("%d ", table[i][j]);
        printf("}\n");
        print_message(reference, buffer);
        if (strcmp(buffer, reference) != 0) {
            printf(HRED "ERROR\n" DEF_COLOR);
            exit(1);
        }
        pclose(output);
        pclose(reference_output);
        i++;
    }
}

void execute_bonus100(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[HUGE_CMD_LEN];
    char reference_cmd[HUGE_CMD_LEN];
    char buffer[BUF_LEN];
    char reference[BUF_LEN];
    FILE *output;
    FILE *reference_output;
    int i = 27;
    int arr_size = 100;

    while (table[i]) {
        build_bonus_string(command, arr_size, i, table);
        build_bonus_reference_string(reference_cmd, arr_size, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, BUF_LEN, output);
        fgets(reference, BUF_LEN, reference_output);
        printf(HBLUE "size(%d):" DEF_COLOR "{ ", arr_size);
        for (int j = 0; j < arr_size; j++)
            printf("%d ", table[i][j]);
        printf("}\n");
        print_message(reference, buffer);
        if (strcmp(buffer, reference) != 0) {
            printf(HRED "ERROR\n" DEF_COLOR);
            exit(1);
        }
        pclose(output);
        pclose(reference_output);
        i++;
    }
}

void execute_bonus500(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[HUGE_CMD_LEN];
    char reference_cmd[HUGE_CMD_LEN];
    char buffer[BUF_LEN];
    char reference[BUF_LEN];
    FILE *output;
    FILE *reference_output;
    int i = 31;
    int arr_size = 500;

    while (table[i]) {
        build_bonus_string(command, arr_size, i, table);
        build_bonus_reference_string(reference_cmd, arr_size, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, BUF_LEN, output);
        fgets(reference, BUF_LEN, reference_output);
        printf(HBLUE "size(%d):" DEF_COLOR "{ ", arr_size);
        for (int j = 0; j < arr_size; j++)
            printf("%d ", table[i][j]);
        printf("}\n");
        print_message(reference, buffer);
        if (strcmp(buffer, reference) != 0) {
            printf(HRED "ERROR\n" DEF_COLOR);
            exit(1);
        }
        pclose(output);
        pclose(reference_output);
        i++;
    }
}

static void print_message(char *reference, char *buffer) {
    if (!strncmp(reference, "OK", 2))
        printf(CYAN "official checker: " GREEN "OK\n" DEF_COLOR);
    else if (strncmp(reference, "KO", 2))
        printf(CYAN "official checker: " RED "KO\n" DEF_COLOR);
    if (!strncmp(buffer, "OK", 2))
        printf(HCYAN "    your checker: " HGREEN "OK\n" DEF_COLOR);
    else if (!strncmp(buffer, "KO", 2))
        printf(HCYAN "    your checker: " HRED "KO\n" DEF_COLOR);
}
