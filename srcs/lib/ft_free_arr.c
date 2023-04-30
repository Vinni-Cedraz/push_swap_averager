#include "averager.h"

void ft_free_arr(char **arr, void **aux) {
    while (arr && *arr) free(*arr++);
    free(aux);
}

void ft_free_arr_size(void **arr, uint size) {
    uint i;

    if (arr == NULL) return;
    i = 0;
    while (i < size) {
        free(arr[i]);
        i++;
    }
    free(arr);
}
