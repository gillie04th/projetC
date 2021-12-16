#include "treelib/treelib.h"
#include <stdio.h>
#include <string.h>
#include <readline/history.h>
#include <stdbool.h>
#include <limits.h>

// Fonction de test des différentes focntionnalités du projet

/** 
 * Si une erreur de mémoire survient, il est possible que la source soit la configuration de votre machine.
 * Dans ce cas soit vous résolvez le problèe vous même, soit vous décommentez la ligne 33 du fichier load.c,
 * à savoir l'instruction "unload(parent->subFolder)".
 **/

int main(int argc, char *argv[])
{
  //printf("==== START ====\n");
  // Initialisation des variables
  string rootPath, configFile = "tree.conf";

  // Allocation de mémoire pour le répertoire racine
  Folder TREE = (Folder)malloc(sizeof(struct Element));

  // Chargement des données dans le fichier de configuration
  loadConf(configFile, &rootPath, "rootdir");
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
    
    printf("\nArborescence des répertoires sous %s :\n", TREE->path);
    //displayTree(TREE);
    /**/
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
    sleep(1);
    search(TREE, argv[1]);
  }

  // Déchargement des données en mémoire
  printf("Libération de la mémoire ...\n");
  sleep(1);
  //unload(TREE);

  printf("==== END ====\n");

  return 0;
}
