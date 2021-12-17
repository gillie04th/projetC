#include "treelib/treelib.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/** 
 * Prend le nom du rep à trouver sur la ligne de commande,
 * l'ecrit dans le fichier /tmp/treeload.data (indiqué dans tree.conf)
 * envoie un signal SIGHUP à treeload
 * **/

string confFile = "tree.conf", pidFile, dataFile;
int pid;

int main(int argc, char *argv[])
{
  loadConf(confFile, &pidFile, "pidfile");
  readInt(pidFile, &pid);
  //printf("%s\n", argv[1]);
  // Test des paramètres entrés dans la ligne de commande
  if (argc < 2)
  {
    printf("Aucun paramètre n'est détecté, aucune recherche ne sera effectuée.\n");
    printf("Usage : ./treeload { fichier | --close } \n");
  }
  else
  {
    if (argc > 2)
    {
      printf("Seul le premier paramètre est utilisé\n");
      sleep(1);
      printf("Il correspond au nom du dossier à rechercher\n");
    }
    char *param = "--close";
    if (strcmp(argv[1], param) == 0)
    {
      printf("Fermeture de treeload\n");
      if(pid) kill(pid, SIGUSR1);
      exit(0);
    }
    printf("Recherche de %s dans l'arborescence\n", argv[1]);
    loadConf(confFile, &dataFile, "datafile");
    writeText(dataFile, argv[1]);
    //if(strcmp(pidFile, "") == 1)
    //else printf("Aucun fichier contenant le pid du programme treeload.\nTentez de relancer treeload.\n");
    if (pid)
      kill(pid, SIGHUP);
  }

  return 0;
}
