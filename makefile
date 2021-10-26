# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c

# règles spécifiques

treetest: treetest.o
	gcc -o treetest treetest.o -l treelib -L treelib -l readline