main: main.c tests/split_string_test.c getopt.c
	gcc -o main main.c tests/split_string_test.c getopt.c -I.