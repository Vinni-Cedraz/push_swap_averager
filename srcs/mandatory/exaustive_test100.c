#include "../include/averager.h"

bool GLOBAL_100 = 0;

static void build_cmd_string(int i, int **table, char command[]) {
    sprintf(
        command,
        "(./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
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
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d) 2>&1",
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

static void *execute_exaustive_sort_t1(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[1500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp1", "a");
    for (int i = 299; i < 319; i++) {
        build_cmd_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
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
    char command[1500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp2", "a");
    for (int i = 319; i < 339; i++) {
        build_cmd_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
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
    char command[1500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp3", "a");
    for (int i = 339; i < 359; i++) {
        build_cmd_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
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
    char command[1500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp4", "a");
    for (int i = 359; i < 379; i++) {
        build_cmd_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
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
    char command[1500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp5", "a");
    for (int i = 379; i < 399; i++) {
        build_cmd_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
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
    char command[1500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp6", "a");
    for (int i = 399; i < 419; i++) {
        build_cmd_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
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
    char command[1500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp7", "a");
    for (int i = 419; i < 439; i++) {
        build_cmd_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
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
    char command[1500];
    char buffer[10];
    FILE *output;
    FILE *fp;

    fp = fopen("tmp8", "a");
    for (int i = 439; i < 459; i++) {
        build_cmd_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
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
