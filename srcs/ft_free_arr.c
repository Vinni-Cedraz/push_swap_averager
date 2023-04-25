#include <stdlib.h>

void ft_free_arr(char **arr, void **aux) {
    while (arr && *arr) free(*arr++);
    free(aux);
}
