libmylib.a:parse.o 
	ar -rs libmylib.a parse.o 
	
# règles spécifiques

#treelib: load.o search.o
#	ar -rs libtreelib.a load.o search.o -lm

parse.o: parse.c treelib.h
	gcc -Wall -c parse.c -lm

search.o: search.c treelib.h
	gcc -Wall -c search.c -lm

load.o: load.c treelib.h
	gcc -Wall -c load.c -lm

