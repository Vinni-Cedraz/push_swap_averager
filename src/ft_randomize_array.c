#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ft_randomize_array(int *arr, int arr_size) {
    int i;
    int j;
    int temp;

    srand(time(NULL));
    i = arr_size - 1;
    while (i > 0) {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i--;
    }
}
