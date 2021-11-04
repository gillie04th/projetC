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

int main(int argc, char *argv[])
{
  printf("==== START ====\n");
  // Initialisation des variables
  string rootPath, configFile = "tree.conf";

  // Allocation de mémoire pour le répertoire racine
  Folder TREE = (Folder)malloc(sizeof(struct Element));

  // Chargement des données dans le fichier de configuration
  loadConf(configFile, &rootPath);
  printf("Le répertoire racine est %s\n", rootPath);

  // Affectation du chemin au répertoire racine
  strcpy(TREE->path, rootPath);

  // Chargement de l'arbre en mémoire
  load(TREE, TREE->path);
  printf("Chargement de l'arbre ...\n");
  sleep(1);

  // Tests sur l'arbre
  printf("Test de l'arborescence ...\n");
  sleep(1);
  if (TREE != NULL) // Si la racine est pleine
  {
    printf("La racine est pleine.\n");
    /*
    printf("\nArborescence des répertoires sous %s :\n", TREE->path);
    displayTree(TREE);
    */
  }
  else // Si elle est vide
    printf("La racine est vide !\n");

  // Test des paramètres entrés dans la ligne de commande
  if (argc < 2)
  {
    printf("Aucun paramètre n'est détecté, aucune recherche ne sera effectuée.\n");
  }
  else
  {
    if (argc > 2)
    {
      printf("Seul le premier paramètre est utilisé.\n");
      sleep(1);
      printf("Il correspond au nom du dossier à rechercher.\n");
    }
    printf("Recherche de %s dans l'arborescence ...\n", argv[1]);
    search(TREE, argv[1]);
  }

  // Déchargement des données en mémoire
  printf("Libération de la mémoire ...\n");
  sleep(1);
  unload(TREE);

  printf("==== END ====\n");

  return 0;
}
