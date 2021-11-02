
#include "treelib.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires

// Affiche récursivement les répertoires
void displayTree(Folder folder)
{
  if (folder != NULL)
  {
    printf("%s\n", folder->path);
    sleep(1);
    //if(folder->subFolder != NULL)
    // Passe au sous dossier
    displayTree(folder->subFolder);
    //if(folder->nextFolder != NULL)
    // Passe au dossier suivant
    displayTree(folder->nextFolder);
  }
}

// Décharge les répertoires stockés en mémoire
void unload(Folder parent)
{
  if (parent != NULL)
  {
    //printf("start");
    unload(parent->subFolder);
    //printf("sub->next");
    unload(parent->nextFolder);
    //printf("next->end");
    free(parent);
    //printf("end");
  }
}

// Charge récursivement les sous répertoires d'un dossier parent.
void load(Folder parent, string path)
{
  // Initialisation des variables
  DIR *dp;
  struct dirent *dirp;

  // Test si le chemin est NULL
  if (path == NULL)
  {
    fprintf(stderr, "Usage: ./program directory_name\n");
    exit(EXIT_FAILURE);
  }

  // Copie le chemin dans le chemin parent (utile uniquement pour le répertoire parent)
  strcpy(parent->path, path);
  errno = 0;

  // Ouverture du dossier
  if ((dp = opendir(path)) != NULL)
  {
    // Initialisation des variables de la boucle
    Folder tmpFolder = NULL, folder;
    string subPath;
    // Boucle qui parcourt tous les sous dossiers du répertoire parent
    while ((dirp = readdir(dp)) != NULL)
    {
      // Test si le repertoire est le répertoire courrant ou parent, et vérifie que les occurrences sont des répertoires
      if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0 && dirp->d_type == 4)
      {
        // Allocation de la mémoire pour le répertoire
        folder = (Folder)malloc(sizeof(struct Element));
        /** On affecte NULL au sous-répertoire pour éviter les erreurs
         * (utile dans le cas du derier répertoire de la liste) **/
        folder->subFolder = NULL;
        // Construction du chemin du sous dossier
        strcpy(subPath, path);
        strcat(subPath, "/");
        strcat(subPath, dirp->d_name);
        // Affectation de son chemin et de son nom au sous répertoire
        strcpy(folder->path, subPath);
        strcpy(folder->name, dirp->d_name);
        // On chaine le précedent dossier au répertoire courrant (NULL dans le premier cas)
        folder->nextFolder = tmpFolder;
        // On garde en mémoire le dossier pour l'utiliser pour chainer les dossiers
        tmpFolder = folder;
        // Chargement de sous-répertoires du répertoire initialisé auparavant
        load(folder, folder->path);
      }
    }
    // Fermeture du dossier
    if (closedir(dp) == -1)
      perror("closedir");
    // Affectation du dernier répertoire de la liste au répertoire parent
    parent->subFolder = folder;
  }
}