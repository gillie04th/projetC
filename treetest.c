/*
Ecrire 2 fonctions : load qui charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires, et search qui localise les occurrences d’une entrée donnée (dont le nom est fourni en argument) dans la structure de données précédente.
Créer une bibliothèque contenant ces 2 fonctions (et éventuellement d’autres fonctions ayant un potentiel de réutilisation).
Construire un programme treetest pour tester ces 2 fonctions. treetest est appelé avec un nom de fichier en argument (sur la ligne de commande), et écrit les emplacements correspondants.
treetest lit d’autres paramètres dans un fichier de configuration tree.conf.
tree.conf définit différentes variables. A ce stade, on commence par une seule variable rootdir spécifiant la racine de l’arborescence à traiter.
	Optionnellement, on pourra clarifier le fichier de configuration en autorisant les lignes blanches et les commentaires (sous une forme à choisir).
exemple de fichier tree.conf autorisant les commentaires
Faire en sorte que le programme utilise ce fichier de configuration.
*/

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

  // Initialisation des variables
  FILE *fichier;
  string rootdir;
  string champ;
  string line;
  Folder subFolder, folder, origin;
  // Allocation de mémoire pour le répertoire racine
  origin = (Folder)malloc(sizeof(struct Element));

  // Ouverture du fichier de configuration et lecture du répertoire source
  fichier = fopen("tree.conf", "r");
  while (1)
  {
    if (fgets(line, 150, fichier) == NULL)
      break;
    if (*line == '#') // Si la ligne commence par un # (commentaire)
      continue; // la ligne est ignorée
    if (sscanf(line, "rootdir=%s", rootdir) != 4) // Sinon on sélectionne la chaine après "rootdir="
    {
      //printf("error yes\n");
    }
    else
    {
      //printf("error no\n");
    }
  }
  //printf("Répertoire racine : %s\n", rootdir);

  // Affectation du chemin au répertoire racine
  strcpy(origin->path, rootdir);

  // Chargement de l'arbre en mémoire
  load(origin, origin->path);

  // Tests sur l'arbre
  if (origin != NULL) // Si la racine est pleine
  {
    printf("La racine est pleine ...\n");
    printf("\nArborescence des répertoires sous %s :\n", origin->path);
    displayTree(origin);
  }
  else // Si elle est vide
    printf("La racine est vide !\n");

  // Déchargement des données en mémoire
  unload(origin);

  //search(1,argv[1]);	// ou  (2,argv[1]);

  printf("==== END ====\n");

  return 0;
}
