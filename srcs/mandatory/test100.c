#include "averager.h"

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

static void *execute_push_swap_t1(void *args_void) {
    t_uargs *args = (t_uargs *)args_void;
    uint **table = args->table;
    char command[CMD_LEN];
    char buffer[10];
    int i = 0;
    FILE *output;
    FILE *fp;

    fp = fopen("tmp1", "a");
    while (table[i][0] != 1) i++;
    while (table[i][0] >= 1 && table[i][0] <= 12) {
		build_averager_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str);
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
    char command[CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp2", "a");

    while (table[i][0] != 13) i++;
    while (table[i][0] >= 13 && table[i][0] <= 24) {
		build_averager_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str);
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
    char command[CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp3", "a");
    while (table[i][0] != 25) i++;
    while (table[i][0] >= 25 && table[i][0] <= 36) {
		build_averager_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str);
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
    char command[CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp4", "a");
    while (table[i][0] != 37) i++;
    while (table[i][0] >= 37 && table[i][0] <= 48) {
		build_averager_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str);
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
    char command[CMD_LEN];
    char buffer[10];
    int i = 0;
    FILE *output;
    FILE *fp;

    fp = fopen("tmp5", "a");
    while (table[i][0] != 49) i++;
    while (table[i][0] >= 49 && table[i][0] <= 61) {
		build_averager_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str);
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
    char command[CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp6", "a");
    while (table[i][0] != 62) i++;
    while (table[i][0] >= 62 && table[i][0] <= 74) {
		build_averager_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str);
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
    char command[CMD_LEN];
    char buffer[10];
    FILE *output;
    FILE *fp;
    int i = 0;

    fp = fopen("tmp7", "a");
    while (table[i][0] != 75) i++;
    while (table[i][0] >= 75 && table[i][0] <= 87) {
		build_averager_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str);
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
		build_averager_test_cmd_string(command, 100, i, table);
        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, HBLUE"arr[%d]: "DEF_COLOR
		" ./push_swap ", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, " number of operations: %s", out_str);
		handle_err(table, 100, i, out_str);
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
