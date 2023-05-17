#include "averager.h"

static void build_command_string(int i, int **table, char command[]) {
    sprintf(command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
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

static void *execute_exaustive_sort_t1(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp1", "a");
    for (int i = 99; i < 119; i++) {
        build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 20; j++) fprintf(fp, "%d ", table[i][j]);
		fprintf_ok_ko(out_str, fp);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t2(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp2", "a");
    for (int i = 119; i < 139; i++) {
        build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 20; j++) fprintf(fp, "%d ", table[i][j]);
		fprintf_ok_ko(out_str, fp);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t3(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp3", "a");
    for (int i = 139; i < 159; i++) {
        build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 20; j++) fprintf(fp, "%d ", table[i][j]);
		fprintf_ok_ko(out_str, fp);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t4(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp4", "a");
    for (int i = 159; i < 179; i++) {
        build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 20; j++) fprintf(fp, "%d ", table[i][j]);
		fprintf_ok_ko(out_str, fp);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t5(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp5", "a");
    for (int i = 179; i < 199; i++) {
        build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 20; j++) fprintf(fp, "%d ", table[i][j]);
		fprintf_ok_ko(out_str, fp);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t6(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp6", "a");
    for (int i = 199; i < 219; i++) {
        build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 20; j++) fprintf(fp, "%d ", table[i][j]);
		fprintf_ok_ko(out_str, fp);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t7(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp7", "a");
    for (int i = 219; i < 239; i++) {
        build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 20; j++) fprintf(fp, "%d ", table[i][j]);
		fprintf_ok_ko(out_str, fp);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t8(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp8", "a");
    for (int i = 239; i < 259; i++) {
        build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 20; j++) fprintf(fp, "%d ", table[i][j]);
		fprintf_ok_ko(out_str, fp);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

void exaustive_test20(void *args_void) {
    pthread_t pthread[8];
    pthread_create(&pthread[0], NULL, execute_exaustive_sort_t1, args_void);
    pthread_create(&pthread[1], NULL, execute_exaustive_sort_t2, args_void);
    pthread_create(&pthread[2], NULL, execute_exaustive_sort_t3, args_void);
    pthread_create(&pthread[3], NULL, execute_exaustive_sort_t4, args_void);
    pthread_create(&pthread[4], NULL, execute_exaustive_sort_t5, args_void);
    pthread_create(&pthread[5], NULL, execute_exaustive_sort_t6, args_void);
    pthread_create(&pthread[6], NULL, execute_exaustive_sort_t7, args_void);
    pthread_create(&pthread[7], NULL, execute_exaustive_sort_t8, args_void);
    int count = -1;
    while (++count < 8) {
        pthread_join(pthread[count], NULL);
    }
}
