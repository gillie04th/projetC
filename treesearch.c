#include "treelib/treelib.h"
#include <stdio.h>
#include <signal.h>

/**
 * Auteur : GILLIER Théophile
*/

// Initialisation des variables
string confFile = "tree.conf", pidFile, dataFile;
int pid;

// Fonction principale envoyant les signaux au programme
int main(int argc, char *argv[])
{
  // Chargement du chemin vers le fichier contenant le pid du programme principale
  loadConf(confFile, &pidFile, "pidfile");
  // Lecture du pid dans le fichier
  readInt(pidFile, &pid);
  // Test des paramètres entrés dans la ligne de commande
  if (argc < 2)
  {
    // Si aucun argument n'est passer sur la ligne de commande
    printf("Aucun paramètre n'est détecté, aucune recherche ne sera effectuée.\n");
    printf("Usage : ./treeload { fichier | --close } \n");
  }
  else
  {
    if (argc > 2)
    {
      // Si il y a plus d'un paramètre passer en argument
      printf("Seul le premier paramètre est utilisé\n");
      sleep(1);
      printf("Il correspond au nom du dossier à rechercher\n");
    }
    /* Condition de fermeture */
    char *param = "--close";
    // Si le paramètre passé est --close
    if (strcmp(argv[1], param) == 0)
    {
      // On envoie un signal SIGUSR1 au programme principale
      if(pid) kill(pid, SIGUSR1);
      // On ferme ce programme
      exit(0);
    }
    /* */
    // On charge le chemin vers le fichier devant contenir le nom du dossier à rechercher
    loadConf(confFile, &dataFile, "datafile");
    // On écrit le nom du dossier à rechercher
    writeText(dataFile, argv[1]);
    // Envoie du signal au programme principale
    if (pid)
      kill(pid, SIGHUP);
  }

  return 0;
}
