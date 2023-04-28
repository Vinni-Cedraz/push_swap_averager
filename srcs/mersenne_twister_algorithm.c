#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "colors.h"
#define MT_LEN 624
#define MT_IA 397

typedef unsigned int uint;

struct MT {
    uint state[MT_LEN];
    int next;
};

void mt_init(struct MT *m, uint seed) {
    int i;

    m->state[0] = seed;
    for (i = 1; i < MT_LEN; i++) {
        m->state[i] =
            1812433253 * (m->state[i - 1] ^ (m->state[i - 1] >> 30)) + i;
    }
    m->next = MT_LEN;
}

uint mt_generate(struct MT *m) {
    uint y;
    static uint mag[2] = {0x0, 0x9908b0df};
    int i = m->next;

    if (i >= MT_LEN) {
        int k;

        if (i == MT_LEN + 1)
            mt_init(m, 5489);

        for (k = 0; k < MT_LEN - MT_IA; k++) {
            y = (m->state[k] & 0x80000000) | (m->state[k + 1] & 0x7fffffff);
            m->state[k] = m->state[k + MT_IA] ^ (y >> 1) ^ mag[y & 0x1];
        }
        for (; k < MT_LEN - 1; k++) {
            y = (m->state[k] & 0x80000000) | (m->state[k + 1] & 0x7fffffff);
            m->state[k] =
                m->state[k + (MT_IA - MT_LEN)] ^ (y >> 1) ^ mag[y & 0x1];
        }
        y = (m->state[MT_LEN - 1] & 0x80000000) | (m->state[0] & 0x7fffffff);
        m->state[MT_LEN - 1] = m->state[MT_IA - 1] ^ (y >> 1) ^ mag[y & 0x1];

        i = 0;
    }

    y = m->state[i];
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680;
    y ^= (y << 15) & 0xefc60000;
    y ^= (y >> 18);

    m->next = i + 1;
    return y;
}

void shuffle_array(uint *arr, int len, uint seed) {
    struct MT mt;
    int i, j;
    uint tmp;

    mt_init(&mt, seed);

    for (i = len - 1; i > 0; i--) {
        j = mt_generate(&mt) % (i + 1);
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

//
// int main() {
//     int i;
//     uint arr[500];
//
//     for (i = 1; i < 500; i++) arr[i] = i;
//
//     shuffle_array(arr, 500);
//
//     for (i = 0; i < 500; i++) printf("%u ", arr[i]);
// }
