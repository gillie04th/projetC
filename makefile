# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c

# règles spécifiques

treetest: treetest.o
	gcc -Wall -o treetest treetest.c -l treelib -L treelib

treeload: treeload.o
	gcc -Wall -o treeload treeload.c -l treelib -L treelib

treesearch: treesearch.o
	gcc -Wall -o treesearch treesearch.c -l treelib -L treelib