#include "averager.h"

bool GLOBAL_100 = 0;

static void *execute_exaustive_sort_t1(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[MEDIUM_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp1", "a");
    for (int i = 299; i < 319; i++) {
        build_exaustive_checker_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++)
            fprintf(fp, "%d ", table[i][j]);
        fprintf_ok_ko(out_str, fp, &GLOBAL_100);
        handle_err(table, 100, i, out_str);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t2(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[MEDIUM_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp2", "a");
    for (int i = 319; i < 339; i++) {
        build_exaustive_checker_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++)
            fprintf(fp, "%d ", table[i][j]);
        fprintf_ok_ko(out_str, fp, &GLOBAL_100);
        handle_err(table, 100, i, out_str);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t3(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[MEDIUM_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp3", "a");
    for (int i = 339; i < 359; i++) {
        build_exaustive_checker_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++)
            fprintf(fp, "%d ", table[i][j]);
        fprintf_ok_ko(out_str, fp, &GLOBAL_100);
        handle_err(table, 100, i, out_str);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t4(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[MEDIUM_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp4", "a");
    for (int i = 359; i < 379; i++) {
        build_exaustive_checker_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++)
            fprintf(fp, "%d ", table[i][j]);
        fprintf_ok_ko(out_str, fp, &GLOBAL_100);
        handle_err(table, 100, i, out_str);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t5(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[MEDIUM_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp5", "a");
    for (int i = 379; i < 399; i++) {
        build_exaustive_checker_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++)
            fprintf(fp, "%d ", table[i][j]);
        fprintf_ok_ko(out_str, fp, &GLOBAL_100);
        handle_err(table, 100, i, out_str);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t6(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[MEDIUM_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp6", "a");
    for (int i = 399; i < 419; i++) {
        build_exaustive_checker_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++)
            fprintf(fp, "%d ", table[i][j]);
        fprintf_ok_ko(out_str, fp, &GLOBAL_100);
        handle_err(table, 100, i, out_str);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t7(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[MEDIUM_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp7", "a");
    for (int i = 419; i < 439; i++) {
        build_exaustive_checker_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++)
            fprintf(fp, "%d ", table[i][j]);
        fprintf_ok_ko(out_str, fp, &GLOBAL_100);
        handle_err(table, 100, i, out_str);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_exaustive_sort_t8(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[MEDIUM_CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp8", "a");
    for (int i = 439; i < 459; i++) {
        build_exaustive_checker_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++)
            fprintf(fp, "%d ", table[i][j]);
        fprintf_ok_ko(out_str, fp, &GLOBAL_100);
        handle_err(table, 100, i, out_str);
        pclose(output);
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

void exaustive_test100(void *args_void) {
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
    create_unified_log_file100();
}

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table2();
    exaustive_test100(args);
    ft_free_arr_size((void **)args->table, 1000);
    free(args);
    if (1 == GLOBAL_100) {
        dprintf(1,
                RED "One or more sorting tests " HRED "FAILED!!!\n" YELLOW
                    "to see the details run: " DEF_COLOR
                    "cat push_swap_averager/log_files/exaustive100.log\n\n\n");
        return 1;
    }
}
