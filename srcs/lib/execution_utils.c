#include "../include/averager.h"

void exec_each_function_in(void (*array_of_function_ptrs[])(char *str), char *str) {
    while (*array_of_function_ptrs)
        (*array_of_function_ptrs++)(str);
}

void bonus_exec_each_function_in(void (*array_of_function_ptrs[])(t_args *args), t_args *args) {
    while (*array_of_function_ptrs)
        (*array_of_function_ptrs++)(args);
}

char *execute_cmd(char cmd[], char buffer[], FILE *output) {
    output = popen(cmd, "r");
    char *out_str = fgets(buffer, 10, output);
    pclose(output);
    return out_str;
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

void trim_linebreak(char *str) {
    int len = 0;
    if (str)
        len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

static void analyse_error_log_file(char line[500], char cmd[500], bool bonus) {
    ssize_t read;
    FILE *error_log = fopen("error.log", "r");
    if (error_log == NULL) {
        perror("Error opening file");
        exit(errno);
    }
    fseek(error_log, 0, SEEK_END);
    if (ftell(error_log) == 0) {
        log_error(LOG_FILE, line, cmd);
        return;
    }
    rewind(error_log);
    if ((read = fread(line, sizeof(char), 500, error_log)) != -1) {
        if (!strcmp(line, "Error\n")) {
			printf(GREEN"OK"DEF_COLOR);
			bonus ? printf("\n") : printf(" <---- %s\n", cmd);
        } else if (NULL != strstr(line, "egmentation")) {
            printf(RED "KO" DEF_COLOR "	<---- SEGFAULT\n");
            exit(1);
        } else if (NULL != strstr(line, "memcheck")) {
            printf(RED "KO" DEF_COLOR "	<---- MEMORY LEAK on %s\n", cmd);
        } else
        	log_error(LOG_FILE, line, cmd);
    }
    fclose(error_log);
}

void exec_test_and_analyse_output(char *cmd, bool empty_expected, bool bonus) {
    FILE *fp;
    char line[CMD_LEN] = {0};
    switch (empty_expected) {
    case CMD_OUTPUT:
        open_process_and_exec_cmd_there(&fp, cmd, DONT_CLOSE_PROCESS_AFTER);
        analyse_cmd_output(line, fp, cmd, bonus);
        pclose(fp);
        break;
    case LOG_FILE:
        open_process_and_exec_cmd_there(&fp, cmd, CLOSE_PROCESS_AFTER);
        analyse_error_log_file(line, cmd, bonus);
        break;
    }
}
