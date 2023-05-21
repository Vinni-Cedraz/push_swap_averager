#include "../include/averager.h"

static void execute_memtests(void *args_void) {
  t_args *args = (t_args *)args_void;
  int **table = args->table;
  char buffer[100];
  char cmd[10000];
  FILE *output;
  int i = 1;

  while (table[i]) {
    build_memtest3_string(cmd, i, table);
    output = popen(cmd, "r");
    fgets(buffer, 100, output);
	log_cmd_and_output(table, 3, i, buffer);
	fprintf_ok_ko(buffer, output, NULL);
    pclose(output);
    i++;
  }

  i = 1;
  while (table[i]) {
    build_test3_string(cmd, i, table);
    output = popen(cmd, "r");
    fgets(buffer, 100, output);
	log_cmd_and_output_3(table, 3, i, buffer);
    pclose(output);
    i++;
  }

   dprintf(1, WHITE "\nMEMORY AND SORTING TESTS\n" DEF_COLOR CYAN
                    "	with valgrind -q \n\n\n" DEF_COLOR);
  i += 2;
  int size = 5;

  execute_memtest(table, size, i, buffer, cmd, build_memtest5_string);
  i = 11;
  size = 10;

  build_memtest10_string(cmd, i, table);
  output = popen(cmd, "r");
  fgets(buffer, 100, output);
  log_cmd_and_output(table, size, i, buffer);
  fprintf_ok_ko(buffer, output, NULL);
  pclose(output);

  i = 15;
  size = 15;

  build_memtest15_string(cmd, i, table);
  output = popen(cmd, "r");
  fgets(buffer, 100, output);
  log_cmd_and_output(table, size, i, buffer);
  fprintf_ok_ko(buffer, output, NULL);
  pclose(output);

  i = 19;
  size = 20;

  build_memtest20_string(cmd, i, table);
  output = popen(cmd, "r");
  fgets(buffer, 100, output);
  log_cmd_and_output(table, size, i, buffer);
  fprintf_ok_ko(buffer, output, NULL);
  pclose(output);

  i = 27;
  size = 100;

  build_memtest100_string(cmd, i, table);
  output = popen(cmd, "r");
  fgets(buffer, 100, output);
  log_cmd_and_output(table, size, i, buffer);
  fprintf_ok_ko(buffer, output, NULL);
  pclose(output);

  i = 31;
  size = 500;

  build_memtest500_string(cmd, i, table);
  output = popen(cmd, "r");
  fgets(buffer, 100, output);
  log_cmd_and_output(table, size, i, buffer);
  fprintf_ok_ko(buffer, output, NULL);
  pclose(output);
}

int main(void) {
  t_args *args = malloc(sizeof(t_args));
  args->table = init_table();
  dprintf(1, HRED "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "
                  "FLAG\n\n\n" DEF_COLOR);
  sleep(3);
  dprintf(1, WHITE "BASIC TESTS\n" DEF_COLOR);
  dprintf(1, CYAN "	with valgrind -q\n" DEF_COLOR);
  execute_memtests(args);
  dprintf(1, CYAN "\n\n\nIf you didnt see any valgrind messages it means no "
                  "memory leaks were found in your program\n\n\n\n" DEF_COLOR);
  dprintf(1,
          HCYAN "Now, we will check sorting correctness with several different "
                "permutations...\n" DEF_COLOR);
  exaustive_test20(args);
  ft_free_arr_size((void **)args->table, 1000);
  free(args);
  dprintf(
      1, GREEN
      "Sorting checks are done ->	" CYAN
      "No (FAILED) messages in the next lines will mean its OK\n\n" DEF_COLOR);
}
