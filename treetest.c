/*
Ecrire 2 fonctions : load qui charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires, et search qui localise les occurrences d’une entrée donnée (dont le nom est fourni en argument) dans la structure de données précédente.
Créer une bibliothèque contenant ces 2 fonctions (et éventuellement d’autres fonctions ayant un potentiel de réutilisation).
Construire un programme treetest pour tester ces 2 fonctions. treetest est appelé avec un nom de fichier en argument (sur la ligne de commande), et écrit les emplacements correspondants.
treetest lit d’autres paramètres dans un fichier de configuration tree.conf.
tree.conf définit différentes variables. A ce stade, on commence par une seule variable rootdir spécifiant la racine de l’arborescence à traiter.
	Optionnellement, on pourra clarifier le fichier de configuration en autorisant les lignes blanches et les commentaires (sous une forme à choisir).
exemple de fichier tree.conf autorisant les commentaires
# racine des répertoires à charger
rootdir=/var
Faire en sorte que le programme utilise ce fichier de configuration.
Rédiger un Makefile pour la bibliothèque et un autre pour le programme.*/

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "treelib/treelib.h"
#include <stdbool.h>
#include <limits.h>

#define ConfigFile "tree.conf" //sans commentaire ou ligne blanche

int main()
{
  printf("==== START ====\n");
  Folder subFolder, folder, origin;
  origin = (Folder)malloc(sizeof(struct Element));
  strcpy(origin->path,"/etc");

  load(origin, origin->path);

  folder = origin->subFolder;

  //printf("%d\n", isSymlink(path));

  if (origin != NULL)
  {
    printf("origin est plein\n"); //////////
    if (folder != NULL)
    {
      printf("origin->path : %s\n", origin->path);
      displayTree(origin);
    }
    else
      printf("origin->Folders est null\n");
  }
  else
    printf("origin est null\n");

  unload(origin);

  printf("==== END ====\n");

  printf("\n");
	  
  //search(1,argv[1]);	// ou  (2,argv[1]);
	
  return 0;
}
