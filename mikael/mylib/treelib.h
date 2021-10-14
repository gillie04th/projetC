
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>  
#include <dirent.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

#define VRAI 1
#define FAUX 0
#define N 11

void search();

void load();

typedef char string[N];

int parse(const char *src, char *v1, char *v2);
