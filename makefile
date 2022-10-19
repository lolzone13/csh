main: main.c tests/split_string_test.c
	gcc -o main main.c tests/split_string_test.c -I.