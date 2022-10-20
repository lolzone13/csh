#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

void split_string_test() {


    char split_string_test[] = "hello world yes";
    char need_string[3][6] = {"hello", "world", "yes"};
    
    char **split_lines = lsh_split_line(split_string_test);
    int test_len = sizeof(need_string)/sizeof(need_string[0]);
    for(int i = 0; i<test_len; i++) {
        
        assert(strcmp(split_lines[i],need_string[i]) == 0);
    }
    printf("\x1b[32m" "split_string_test successful \n" "\x1b[0m");
    free(split_lines);
    return;
}