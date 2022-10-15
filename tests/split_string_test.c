#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "functions.h";

int main() {


    char split_string_test[] = "hello world yes";
    char need_string[3][6] = {"hello", "world", "yes"};
    
    char **split_lines = lsh_split_line(split_string_test);
    int test_len = sizeof(need_string)/sizeof(need_string[0]);
    for(int i = 0; i<test_len; i++) {
        printf("%s\n", split_lines[i]);
        assert(strcmp(split_lines[i],need_string[i]) == 0);
    }

    return 0;
}