#include "averager.h"

static uint **init_permutation_table(void) {
  int count = 0;
  uint *tmp_arr = malloc(sizeof(uint *) * 500);
  uint **table = calloc(sizeof(uint *), 481);
  for (int i = 0; i < 500; i++)
    tmp_arr[i] = i;
  srand(time(NULL) ^ (getpid() << 16));
  shuffle_array(tmp_arr, 500, rand());

  while (count < 480) {
    if (count % 60 == 0)
      table[count] = NULL;
    else if (!is_repeated500(table, tmp_arr, count)) {
      table[count] = calloc(sizeof(uint), 500);
      memcpy(table[count], tmp_arr, 500 * sizeof(uint));
    }
    shuffle_array(tmp_arr, 500, rand());
    count++;
  }

  free(tmp_arr);
  return table;
}

static void *execute_push_swap_t1(void *args_void) {
  t_uargs *args = (t_uargs *)args_void;
  uint **table = args->table;
  char command[BIG_CMD_LEN];
  char buffer[10];
  int i = 0;
  FILE *output;
  FILE *fp;

  fp = fopen("tmp1", "a");
  while (table[i]) {
    build_averager_test_cmd_string(command, 500, i, table);
    output = popen(command, "r");
    char *out_str = fgets(buffer, 10, output);
    fprintf(fp, BLUE "arr[%d]:" DEF_COLOR, i);
    fprintf(fp, " ./push_swap ");
    for (int j = 0; j < 500; j++)
      fprintf(fp, "%d ", table[i][j]);
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
    handle_err(table, 500, i, out_str);
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
  char command[BIG_CMD_LEN];
  char buffer[10];
  int null_count = 0;
  FILE *output;
  FILE *fp;
  int i = 61;

  fp = fopen("tmp2", "a");
  while (table[i]) {
    build_averager_test_cmd_string(command, 500, i, table);
    output = popen(command, "r");
    char *out_str = fgets(buffer, 10, output);
    fprintf(fp, BLUE "arr[%d]:" DEF_COLOR, i);
    fprintf(fp, " ./push_swap ");
    for (int j = 0; j < 500; j++)
      fprintf(fp, "%d ", table[i][j]);
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
    handle_err(table, 500, i, out_str);
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
  char command[BIG_CMD_LEN];
  char buffer[10];
  FILE *output;
  FILE *fp;
  int i = 121;
  int null_count = 0;

  fp = fopen("tmp3", "a");
  while (table[i]) {
    build_averager_test_cmd_string(command, 500, i, table);
    output = popen(command, "r");
    char *out_str = fgets(buffer, 10, output);
    fprintf(fp, BLUE "arr[%d]:" DEF_COLOR, i);
    fprintf(fp, " ./push_swap ");
    for (int j = 0; j < 500; j++)
      fprintf(fp, "%d ", table[i][j]);
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
    handle_err(table, 500, i, out_str);
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
  char command[BIG_CMD_LEN];
  char buffer[10];
  FILE *output;
  FILE *fp;
  int i = 181;
  int null_count = 0;

  fp = fopen("tmp4", "a");
  while (table[i]) {
    build_averager_test_cmd_string(command, 500, i, table);
    output = popen(command, "r");
    char *out_str = fgets(buffer, 10, output);
    fprintf(fp, BLUE "arr[%d]:" DEF_COLOR, i);
    fprintf(fp, " ./push_swap ");
    for (int j = 0; j < 500; j++)
      fprintf(fp, "%d ", table[i][j]);
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
    handle_err(table, 500, i, out_str);
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
  char command[BIG_CMD_LEN];
  char buffer[10];
  int i = 241;
  FILE *output;
  FILE *fp;
  int null_count = 0;

  fp = fopen("tmp5", "a");
  while (table[i]) {
    build_averager_test_cmd_string(command, 500, i, table);
    output = popen(command, "r");
    char *out_str = fgets(buffer, 10, output);
    fprintf(fp, BLUE "arr[%d]:" DEF_COLOR, i);
    fprintf(fp, " ./push_swap ");
    for (int j = 0; j < 500; j++)
      fprintf(fp, "%d ", table[i][j]);
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
    handle_err(table, 500, i, out_str);
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
  char command[BIG_CMD_LEN];
  char buffer[10];
  FILE *output;
  FILE *fp;
  int i = 301;
  int null_count = 0;

  fp = fopen("tmp6", "a");
  while (table[i]) {
    build_averager_test_cmd_string(command, 500, i, table);
    output = popen(command, "r");
    char *out_str = fgets(buffer, 10, output);
    fprintf(fp, BLUE "arr[%d]:" DEF_COLOR, i);
    fprintf(fp, " ./push_swap ");
    for (int j = 0; j < 500; j++)
      fprintf(fp, "%d ", table[i][j]);
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
    handle_err(table, 500, i, out_str);
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
  char command[BIG_CMD_LEN];
  char buffer[10];
  FILE *output;
  FILE *fp;
  int i = 361;
  int null_count = 0;

  fp = fopen("tmp7", "a");
  while (table[i]) {
    build_averager_test_cmd_string(command, 500, i, table);
    output = popen(command, "r");
    char *out_str = fgets(buffer, 10, output);
    fprintf(fp, BLUE "arr[%d]:" DEF_COLOR, i);
    fprintf(fp, " ./push_swap ");
    for (int j = 0; j < 500; j++)
      fprintf(fp, "%d ", table[i][j]);
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
    handle_err(table, 500, i, out_str);
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
  char command[BIG_CMD_LEN];
  char buffer[10];
  FILE *output;
  FILE *fp;
  int i = 421;
  int null_count = 0;

  fp = fopen("tmp8", "a");
  while (table[i]) {
    build_averager_test_cmd_string(command, 500, i, table);
    output = popen(command, "r");
    char *out_str = fgets(buffer, 10, output);
    fprintf(fp, HBLUE "arr[%d]:" DEF_COLOR, i);
    fprintf(fp, " ./push_swap ");
    for (int j = 0; j < 500; j++)
      fprintf(fp, "%d ", table[i][j]);
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
    handle_err(table, 500, i, out_str);
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
  printf(WHITE "\nTESTS FOR SIZE 500\n" DEF_COLOR);
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
  while (++count < 8)
    pthread_join(pthread[count], NULL);
  ft_free_arr_size((void **)args->table, 481);
  free(args);
}
