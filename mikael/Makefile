
%: %.c
	gcc -Wall -o $@ $@.c -lm mylib -L mylib -lreadline
	
treetest: treetest.c
	gcc -o treetest treetest.c -l mylib -L mylib -lreadline

