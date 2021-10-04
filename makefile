%: %.c
	gcc -Wall -o $@ $@.c -lm
