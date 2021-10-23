
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

/*
int is_regular_file(const char *path)  //structure pour reconnaitre un fichier
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int isDirectory(const char *path) {   //structure pour reconnaitre un repertoire
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}
*/
//faire fonction pour tester

void search(); //Pas encore finis

void load(); //pas encore finis

typedef char string[N];

int parse(const char *src, char *v1, char *v2); //permet d'appeler la fonction parse à partir de treelib
