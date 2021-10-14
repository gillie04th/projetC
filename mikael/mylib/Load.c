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

#include "../treelib.h"

//charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires

int load(int argc, char *argv[]){
    int load;
    
    DIR *dp;
  struct dirent *dirp;

   if (argc != 2) {
       fprintf(stderr, "Usage: ./program directory_name\n");
       exit(EXIT_FAILURE);
   }

   dp = opendir(argv[1]);

   if(!dp){

     printf("répertoire introuvable ou manque de permission\n");
     return 1;
   }
   while ((dirp = readdir(dp)) != NULL)
      printf("%s\n", dirp->d_name);

  closedir(dp);
  exit(EXIT_SUCCESS);
    
   return load;
}

int main(){
    int a;
    char b;
    load(a,b);
}
