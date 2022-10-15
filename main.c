#include <stdio.h>
#include <stdlib.h>

// global variables
#define BUFFER_SIZE 1024
#define EXIT_FAILURE 1

// colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


//  
char *lsh_read_line() {
    int bufsize = BUFFER_SIZE;
    int position = 0;
    char* buffer = (char *)malloc(bufsize * sizeof(char));
    char c;

    if (!buffer) {
        fprintf(stderr, "csh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        }
        else {
            buffer[position] = c;
        }

        position++;
        if (position >= bufsize) {
            bufsize+=BUFFER_SIZE;
            buffer = realloc(buffer, bufsize);

            if (!buffer) {
                fprintf(stderr, "csh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }




    }

}

char** lsh_split_line(line) {
    return line;
}

int lsh_execute(args) {
    return args;
}

void csh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    } while(status);

}


int main(int argc, char **argv) {

    csh_loop();
    //printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
    return 0;
}