# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c

# règles spécifiques

treelib: load.o search.o
	ar -rs libtreelib.a load.o search.o

search.o: search.c treelib.h
	gcc -Wall -c search.c

load.o: load.c treelib.h
	gcc -Wall -c load.c