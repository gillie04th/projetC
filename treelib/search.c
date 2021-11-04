#include "treelib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

//localise les occurrences d’une entrée donnée (dont le nom est fourni en argument) dans la structure de données précédente(load).

int search(Folder folder, string dirName)
{
   if (strcmp(folder->name, dirName) == 0){
      printf("Un dossier \"%s\" à pour chemin : %s\n",dirName, folder->path);
      sleep(1);
   }
   if (folder->nextFolder != NULL)
      search(folder->nextFolder, dirName);
   if (folder->subFolder != NULL)
      search(folder->subFolder, dirName);

   return 0;
}
