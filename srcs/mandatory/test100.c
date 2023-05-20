#include "../include/averager.h"

bool SEGFAULT_t100 = 0;

static uint **init_permutation_table(void) {
    int count = 0;
    int j = 1;
    uint *tmp_arr;
    uint **table = calloc(sizeof(uint *), 1201);
	srand(time(NULL) ^ (getpid() << 16));

    for (int i = 1; i <= 100; i++) {
        tmp_arr = seq_except(i);
        for (int k = 1; k <= 12; k++) {
            table[count] = malloc(sizeof(uint) * 100);
            table[count][0] = i;
            shuffle_array(tmp_arr, 99, rand());
            if (is_repeated100(table, tmp_arr, count)) {
                k--, free(table[count]);
                continue;
            }
            int k = 0;
            for (j = 1; j < 100; j++) {
                table[count][j] = tmp_arr[k];
                k++;
            }
            count++;
        }
		free(tmp_arr);
    }
    return table;
}

static void build_command_string(int i, uint **table, char command[]) {
    sprintf(
        command,
        "(./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l) 2>&1 ",
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

static void *execute_push_swap_t1(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[500];
    char buffer[10];
    int i = 0;
    FILE *output;
    FILE *fp;

    fp = fopen("tmp1", "a");
    while (table[i][0] != 1) i++;
    while (table[i][0] >= 1 && table[i][0] <= 12) {
		build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str, &SEGFAULT_t100);
        pclose(output);
        i++;
    }

	fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_push_swap_t2(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp2", "a");

    while (table[i][0] != 13) i++;
    while (table[i][0] >= 13 && table[i][0] <= 24) {
		build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str, &SEGFAULT_t100);
        pclose(output);
        i++;
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_push_swap_t3(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp3", "a");
    while (table[i][0] != 25) i++;
    while (table[i][0] >= 25 && table[i][0] <= 36) {
		build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str, &SEGFAULT_t100);
        pclose(output);
        i++;
    }

    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_push_swap_t4(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp4", "a");
    while (table[i][0] != 37) i++;
    while (table[i][0] >= 37 && table[i][0] <= 48) {
		build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str, &SEGFAULT_t100);
        pclose(output);
        i++;
    }

	fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_push_swap_t5(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[500];
    char buffer[10];
    int i = 0;
    FILE *output;
    FILE *fp;

    fp = fopen("tmp5", "a");
    while (table[i][0] != 49) i++;
    while (table[i][0] >= 49 && table[i][0] <= 61) {
		build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str, &SEGFAULT_t100);
        pclose(output);
        i++;
    }

	fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_push_swap_t6(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp6", "a");
    while (table[i][0] != 62) i++;
    while (table[i][0] >= 62 && table[i][0] <= 74) {
		build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str, &SEGFAULT_t100);
        pclose(output);
        i++;
    }

	fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_push_swap_t7(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp7", "a");
    while (table[i][0] != 75) i++;
    while (table[i][0] >= 75 && table[i][0] <= 87) {
		build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str, &SEGFAULT_t100);
        pclose(output);
        i++;
    }

	fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

static void *execute_push_swap_t8(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[5000];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp8", "a");
    while (table[i][0] != 88) i++;
    while (table[i]) {
		build_command_string(i, table, command);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str, &SEGFAULT_t100);
        pclose(output);
        i++;
    }

	fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

int main(void) {
    t_uargs *args = malloc(sizeof(t_uargs));
    pthread_t pthread[8];
    printf(WHITE"\nTESTS FOR SIZE 100\n"DEF_COLOR);
    args->table = init_permutation_table();
    pthread_create(&pthread[0], NULL, execute_push_swap_t1, (void *)args);
    pthread_create(&pthread[1], NULL, execute_push_swap_t2, (void *)args);
    pthread_create(&pthread[2], NULL, execute_push_swap_t3, (void *)args);
    pthread_create(&pthread[3], NULL, execute_push_swap_t4, (void *)args);
    pthread_create(&pthread[4], NULL, execute_push_swap_t5, (void *)args);
    pthread_create(&pthread[5], NULL, execute_push_swap_t6, (void *)args);
    pthread_create(&pthread[6], NULL, execute_push_swap_t7, (void *)args);
    pthread_create(&pthread[7], NULL, execute_push_swap_t8, (void *)args);
    int count = -1;
    while (++count < 8) pthread_join(pthread[count], NULL);
    ft_free_arr((char **)args->table, (void **)args->table);
    free(args);
}
