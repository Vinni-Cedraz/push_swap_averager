#include "averager.h"

static void print_message(char *reference, char *buffer) {
	if (!strncmp(reference, "OK", 2))
		printf(CYAN"official checker: " GREEN"OK\n"DEF_COLOR);
	else if (strncmp(reference, "KO", 2))
		printf(CYAN"official checker: " RED"KO\n"DEF_COLOR);
	if (!strncmp(buffer, "OK", 2))
		printf(HCYAN"    your checker: "HGREEN"OK\n"DEF_COLOR);
	else if (!strncmp(buffer, "KO", 2))
		printf(HCYAN"    your checker: " HRED"KO\n"DEF_COLOR);
}

void execute_bonus5(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[5000];
    char reference_cmd[5000];
    char buffer[10];
    char reference[10];
    FILE *output;
    FILE *reference_output;
    int i = 7;
	int n = 5;

    while (table[i]) {
        build_bonus5_string(command, i, table);
        build_reference5_string(reference_cmd, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, 10, output);
        fgets(reference, 10, reference_output);
        printf(HBLUE"size(%d):"DEF_COLOR"{ ", n);
        for (int j = 0; j < 5; j++) printf("%d ", table[i][j]);
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
    char command[5000];
    char reference_cmd[5000];
    char buffer[10];
    char reference[10];
    FILE *output;
    FILE *reference_output;
    int i = 11;
	int n = 10;

    while (table[i]) {
        build_bonus10_string(command, i, table);
        build_reference10_string(reference_cmd, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, 10, output);
        fgets(reference, 10, reference_output);
        printf(HBLUE"size(%d):"DEF_COLOR"{ ", n);
        for (int j = 0; j < 10; j++) printf("%d ", table[i][j]);
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
    char command[5000];
    char reference_cmd[5000];
    char buffer[10];
    char reference[10];
    FILE *output;
    FILE *reference_output;
    int i = 15;
	int n = 15;

    while (table[i]) {
        build_bonus15_string(command, i, table);
        build_reference15_string(reference_cmd, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, 10, output);
        fgets(reference, 10, reference_output);
        printf(HBLUE"size(%d):"DEF_COLOR"{ ", n);
        for (int j = 0; j < 15; j++) printf("%d ", table[i][j]);
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
    char command[5000];
    char reference_cmd[5000];
    char buffer[10];
    char reference[10];
    FILE *output;
    FILE *reference_output;
    int i = 19;
	int n = 20;

    while (table[i]) {
        build_bonus20_string(command, i, table);
        build_reference20_string(reference_cmd, i, table);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, 10, output);
        fgets(reference, 10, reference_output);
        printf(HBLUE"size(%d):"DEF_COLOR"{ ", n);
        for (int j = 0; j < 20; j++) printf("%d ", table[i][j]);
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
    char command[5000];
    char reference_cmd[5000];
    char buffer[10];
    char reference[10];
    FILE *output;
    FILE *reference_output;
    int i = 27;
	int n = 100;

    while (table[i]) {
        build_bonus100_string(i, table, command);
        build_reference100_string(i, table, reference_cmd);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, 10, output);
        fgets(reference, 10, reference_output);
        printf(HBLUE"size(%d):"DEF_COLOR"{ ", n);
        for (int j = 0; j < 100; j++) printf("%d ", table[i][j]);
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
    char command[5000];
    char reference_cmd[5000];
    char buffer[10];
    char reference[10];
    FILE *output;
    FILE *reference_output;
    int i = 31;
	int n = 500;

    while (table[i]) {
        build_bonus500_string(i, table, command);
        build_reference500_string(i, table, reference_cmd);
        output = popen(command, "r");
        reference_output = popen(reference_cmd, "r");
        fgets(buffer, 10, output);
        fgets(reference, 10, reference_output);
        printf(HBLUE"size(%d):"DEF_COLOR"{ ", n);
        for (int j = 0; j < 500; j++) printf("%d ", table[i][j]);
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

void execute_bonus1000(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[8000];
    char reference_cmd[8000];
    char buffer[10];
    char reference[10];
    FILE *output;
    FILE *reference_output;
    int i = 35;
	int n = 1000;

    build_bonus1000_string(i, table, command);
    build_reference1000_string(i, table, reference_cmd);
    output = popen(command, "r");
    reference_output = popen(reference_cmd, "r");
    fgets(buffer, 10, output);
    fgets(reference, 10, reference_output);
    printf(HBLUE"size(%d):"DEF_COLOR"{ ", n);
    for (int j = 0; j < 1000; j++) printf("%d ", table[i][j]);
    printf("}\n");
	print_message(reference, buffer);
    if (strcmp(buffer, reference) != 0) {
        printf(HRED "ERROR\n" DEF_COLOR);
        exit(1);
    }
    pclose(output);
    pclose(reference_output);
}
