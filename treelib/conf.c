#include "treelib.h"
#include <string.h> 
#include <dirent.h>

void loadConf(string configFile, string *rootdir){
    // Ouverture du fichier de configuration et lecture du répertoire source
  FILE *file;
  string line;
  file = fopen(configFile, "r");
  while (1)
  {
    if (fgets(line, 150, file) == NULL)
      break;
    if (*line == '#') // Si la ligne commence par un # (commentaire)
      continue; // la ligne est ignorée
    if (sscanf(line, "rootdir=%s", *rootdir) != 4) // Sinon on sélectionne la chaine après "rootdir="
    {
      //printf("error yes\n");
    }
    else
    {
      //printf("error no\n");
    }
  }
}