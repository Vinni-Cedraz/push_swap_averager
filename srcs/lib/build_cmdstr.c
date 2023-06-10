#include "../include/averager.h"

void build_test3_string(char memtest[], int i, int **table) {
    sprintf(memtest, "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d | wc -l) 2>&1", table[i][0],
            table[i][1], table[i][2]);
}

void build_memtest3_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d |"
            "./checker_linux %d %d %d) 2>&1",
            table[i][0], table[i][1], table[i][2], table[i][0], table[i][1],
            table[i][2]);
}

void build_memtest5_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d %d | "
            "./checker_linux %d %d %d %d %d) 2>&1",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
}

void build_memtest10_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d %d %d %d %d %d %d | "
            "./checker_linux %d %d %d %d %d %d %d %d %d %d) 2>&1",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9]);
}

void build_memtest15_string(char memtest[], int i, int **table) {
    sprintf(
        memtest,
        "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "|"
        " ./checker_linux %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d) 2>&1",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14]);
}

void build_memtest20_string(char memtest[], int i, int **table) {
    sprintf(
        memtest,
        "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d |"
        "./checker_linux %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d) 2>&1",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19]);
}

void build_memtest100_string(char command[], int i, int **table) {
    sprintf(
        command,
        "(valgrind --leak-check=full --show-leak-kinds=all -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | ./checker_linux %d "
        "%d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d) 2>&1",
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
        table[i][95], table[i][96], table[i][97], table[i][98], table[i][99],
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
