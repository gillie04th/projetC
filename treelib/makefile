# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c

# règles spécifiques

treelib: load.o search.o file.o conf.o
	ar -rs libtreelib.a load.o search.o file.o conf.o

search.o: search.c treelib.h
	gcc -Wall -c search.c

load.o: load.c treelib.h
	gcc -Wall -c load.c

file.o: file.c treelib.h
	gcc -Wall -c file.c

conf.o: conf.c treelib.h
	gcc -Wall -c conf.c