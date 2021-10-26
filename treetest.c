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

#define ORIGINAL "tree.conf" //sans commentaire ou ligne blanche
#define L 60

void treetest(char filename)
{
}

int main()
{
  string path = "/var";

  Tree noeud;
  noeud=(Tree)malloc(sizeof(struct Node));


  load(&noeud, path);
printf("here\n");
  Folder tmp;
  tmp = noeud->Folders;

  if (noeud != NULL)
  {
    printf("noeud est plein\n");//
    if (noeud->Folders != NULL)
    {
      printf("noeud->Folders est plein\n");
      while (tmp != NULL)
      {
        printf("%s", tmp->name);
        tmp = tmp->nextFolder;
      }
    }
    else printf("noeud->Folders est null\n");
  }
  else printf("noeud est null\n");

  //printf("%d\n%d\n", PATH_MAX, FILENAME_MAX);

  return 0;
}