#include "../include/averager.h"

void fprintf_ok_ko(char *out_str, FILE *fp, bool *GLOBAL) {
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

void fprintf_nb_of_op(char *out_str, FILE *fp, bool *error) {
	(void)error;
    fprintf(fp, CYAN "number of operations: %s" DEF_COLOR, out_str);
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
        for (int j = 0; j < size; j++)
            dprintf(1, "%d ", table[i][j]);
        dprintf(1, "\n\n\n");
    } else {
        dprintf(1, HRED "\nMemory error occurred with the test:" DEF_COLOR
                        " ./push_swap  " DEF_COLOR);
        for (int j = 0; j < size; j++)
            dprintf(1, "%d ", table[i][j]);
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
    for (int j = 0; j < size; j++)
        dprintf(1, "%d ", table[i][j]);
    handle_err(table, size, i, buf);
    dprintf(1, YELLOW "\nchecker_linux: ", DEF_COLOR);
}

void log_cmd_and_output_3(int **table, int size, int i, char *buf) {
    dprintf(1, BLUE "arr[%d]:" DEF_COLOR " ./push_swap ", i);
    for (int j = 0; j < 3; j++)
        dprintf(1, "%d ", table[i][j]);
    dprintf(1, CYAN "	Operations: " DEF_COLOR WHITE "%s" DEF_COLOR, buf);
    if (atoi(buf) > 2) {
        dprintf(1, HRED "ERROR:	" RED
                        "exceeded the limit of operations (2)\n" DEF_COLOR);
    }
    handle_err(table, 3, i, buf);
}

void bonus_log_error(bool empty_expected, char *out_str) {
    trim_linebreak(out_str);
    if (empty_expected) {
        printf("Your checker: ");
        printf(HRED "KO " DEF_COLOR);
        printf("-> Expected nothing either on stderr nor on stdout (fd 1 or "
               "2) " DEF_COLOR);
        printf("But found \"%s\" instead\n", out_str);
    } else if (!empty_expected) {
        printf("Your checker: ");
        printf(HRED "KO " DEF_COLOR);
        printf("-> Expected the string \"Error\\n\" on the stderr (fd 2) ");
        printf("But found \"%s\" instead\n" DEF_COLOR, out_str);
    }
}

void trim_linebreak(char *str) {
    int len = 0;
    if (str)
        len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void open_process_and_exec_cmd_there(FILE **fp, char *cmd, bool close) {
    *fp = popen(cmd, "r");
    if (*fp == NULL) {
        perror("popen");
        exit(errno);
    }
    if (close)
        pclose(*fp);
}

void log_error(bool empty_expected, char *out_str, char *cmd) {
    trim_linebreak(out_str);
    if (empty_expected) {
        printf(cmd);
        printf(HRED "KO " DEF_COLOR);
        printf("-> Expected nothing either on stderr nor on stdout (fd 1 or "
               "2) " DEF_COLOR);
        printf("But found \"%s\" instead\n" DEF_COLOR, out_str);
    } else if (!empty_expected) {
        printf(cmd);
        printf(HRED "KO " DEF_COLOR);
        printf("-> Expected the string \"Error\\n\" on the stderr (fd "
               "2) ");
        printf("But found " DEF_COLOR "\"%s\" instead\n" DEF_COLOR, out_str);
    }
}

void print_array_to_file(FILE *fp, int idx, int arr_size, uint **table) {
    fprintf(fp, HBLUE "arr[%d]: " DEF_COLOR " ./push_swap ", idx);
    for (int j = 0; j < arr_size; j++)
        fprintf(fp, "%d ", table[idx][j]);
}

char *execute_cmd(char cmd[], char buffer[], FILE *output) {
    output = popen(cmd, "r");
    char *out_str = fgets(buffer, 10, output);
    pclose(output);
    return out_str;
}
