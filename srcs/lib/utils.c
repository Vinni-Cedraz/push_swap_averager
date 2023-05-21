#include "../include/averager.h"

static int is_reverse_sorted(int *arr, int last_index) {
    for (int i = 0; i < last_index; i++)
        if (arr[i] < arr[i + 1]) return 0;
    return 1;
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

uint *seq_except(int exclude) {
    int j = 0;
    int i = 0;
    uint *arr = malloc(99 * sizeof(uint));
    for (; ++i != 101;)
        if (i != exclude) arr[j++] = i;
    return arr;
}

int is_repeated100(uint **table, uint *tmp_arr, int count) {
    int i = -1;
    while (++i <= count)
        if (!memcmp(table[i], tmp_arr, 70 * sizeof(uint))) return 1;
    return 0;
}

int is_repeated500(uint **table, uint *tmp_arr, int count) {
    int i = -1;
    while (++i <= count) {
        if (!table[i]) continue;
        if (!memcmp(table[i], tmp_arr, 250 * sizeof(uint))) return 1;
    }
    return 0;
}

void fprintf_ok_ko(char *out_str, FILE *fp, short *GLOBAL) {
    if (!strncmp("OK", out_str, 2) && GLOBAL) {
        fprintf(fp, "	checker_linux:" GREEN "%s" DEF_COLOR, out_str);
    } else if (strncmp("OK", out_str, 2) && GLOBAL) {
        (*GLOBAL) = 1;
        fprintf(fp, "	checker_linux:" HRED "%s" DEF_COLOR, out_str);
    } else if (!strncmp("OK", out_str, 2) && !GLOBAL) {
        dprintf(1, GREEN " %s" DEF_COLOR, out_str);
    } else if (strncmp("OK", out_str, 2) && !GLOBAL) {
        dprintf(1, HRED " %s" DEF_COLOR, out_str);
    }
}

void create_unified_log_file20(void) {
    system("cat tmp8 >> tmp7");
    system("cat tmp7 >> tmp6");
    system("cat tmp6 >> tmp5");
    system("cat tmp5 >> tmp4");
    system("cat tmp4 >> tmp3");
    system("cat tmp3 >> tmp2");
    system("cat tmp2 >> tmp1");
    system("cat tmp1 > exaustive20.log");
    system("mv exaustive20.log log_files/");
    system("rm tmp*");
}

void create_unified_log_file100(void) {
    system("cat tmp8 >> tmp7");
    system("cat tmp7 >> tmp6");
    system("cat tmp6 >> tmp5");
    system("cat tmp5 >> tmp4");
    system("cat tmp4 >> tmp3");
    system("cat tmp3 >> tmp2");
    system("cat tmp2 >> tmp1");
    system("cat tmp1 > exaustive100.log");
    system("mv exaustive100.log log_files/");
    system("rm tmp*");
}

static void log_err_to_stdout(int size, int **table, int i, bool segf) {
    if (segf) {
        dprintf(1, HRED "\nSegfault occurred with the test:" DEF_COLOR
                        " ./push_swap  " DEF_COLOR);
        for (int j = 0; j < size; j++) dprintf(1, "%d ", table[i][j]);
        dprintf(1, "\n\n\n");
    } else {
        dprintf(1, HRED "\nMemory error occurred with the test:" DEF_COLOR
                        " ./push_swap  " DEF_COLOR);
        for (int j = 0; j < size; j++) dprintf(1, "%d ", table[i][j]);
        dprintf(1, "\n\n\n");
    }
    exit(1);
}

int handle_err(int **table, int size, int i, char *buf) {
    if (!strncmp("Segmentation", buf, 5) || !strncmp("segmentation", buf, 5)) {
        bool segf = 1;
        log_err_to_stdout(size, table, i, segf);
    } else if (!strncmp("==", buf, 2)) {
        bool segf = 0;
        log_err_to_stdout(size, table, i, segf);
    }
}

void log_cmd_and_output(int **table, int size, int i, char *buf) {
    dprintf(1, HBLUE "(SIZE %d):" DEF_COLOR " ./push_swap ", size);
    for (int j = 0; j < size; j++) dprintf(1, "%d ", table[i][j]);
    handle_err(table, size, i, buf);
    dprintf(1, YELLOW "\nchecker_linux: ", DEF_COLOR);
}

void log_cmd_and_output_3(int **table, int size, int i, char *buf) {
    dprintf(1, BLUE "arr[%d]:" DEF_COLOR " ./push_swap ", i);
    for (int j = 0; j < 3; j++) dprintf(1, "%d ", table[i][j]);
    dprintf(1, CYAN "	Operations: " DEF_COLOR WHITE "%s" DEF_COLOR, buf);
    if (atoi(buf) > 2) {
        dprintf(1, HRED "ERROR:	" RED
                        "exceeded the limit of operations (2)\n" DEF_COLOR);
    }
    handle_err(table, 3, i, buf);
}
