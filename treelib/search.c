#include "treelib.h"
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

//localise les occurrences d’une entrée donnée (dont le nom est fourni en argument) dans la structure de données précédente(load).

int search(int argc, char *argv[]){

   DIR *dp; //
   struct dirent *dirp; // 
    
   if (argc != 2) {
       fprintf(stderr, "Usage: ./program directory_name\n");
       exit(EXIT_FAILURE);
   }

   dp = opendir(argv[1]); //ouvre le repertoire specifié sur la ligne de commande

   if(!dp){

     printf("répertoire introuvable ou manque de permission\n");
     return 1;
   }
   
   while ((dirp = readdir(dp)) != NULL){
      printf("%s\n", dirp->d_name); //liste les entrées du répertoire spécifié sur la ligne de commande.
   }

   closedir(dp);
   exit(EXIT_SUCCESS);

   return 0;    
}
