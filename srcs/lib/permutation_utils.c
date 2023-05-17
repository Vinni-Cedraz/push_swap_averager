#include "averager.h"

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

void fprintf_ok_ko(char *out_str, FILE *fp) {
    if (!strncmp("OK", out_str, 2))
        fprintf(fp, "	checker_linux:" GREEN " %s" DEF_COLOR, out_str);
    else
        fprintf(fp, "	checker_linux:" HRED " %s" DEF_COLOR, out_str);
}
