#include "treelib.h"
#include <string.h> 
#include <dirent.h>

void loadConf(string configFile, string *returnVal, char * param){
    // Ouverture du fichier de configuration et lecture du répertoire source
  FILE *file;
  string line, exp;
  strcat(exp, param);
  strcat(exp,"=%s");
  file = fopen(configFile, "r");
  while (1)
  {
    if (fgets(line, 150, file) == NULL)
      break;
    if (*line == '#') // Si la ligne commence par un # (commentaire)
      continue; // la ligne est ignorée
    if (sscanf(line, exp, *returnVal) != 4); // Sinon on sélectionne la chaine après "rootdir="
  }
}

/*
void writeText(string filename, string text)
{
    // Ouvre le fichier dans lequel écrire
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("%s doit être créer", filename);
    }
    // Ecrit le texte dans le fichier
    fprintf(fp, "%s\n", text);

    // close the file
    fclose(fp);
}

void writeInt(string filename, int number)
{
    // Ouvre le fichier dans lequel écrire
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("%s doit être créer", filename);
    }
    // Ecrit le texte dans le fichier
    fprintf(fp, "%d\n", number);

    // close the file
    fclose(fp);
}
/**/
