#include <stdio.h>
#include <signal.h>

/** 
 * Prend le nom du rep à trouver sur la ligne de commande,
 * l'ecrit dans le fichier /tmp/treeload.data (indiqué dans tree.conf)
 * envoie un signal SIGHUP à treeload
 * **/

int main(int argc, char *argv[])
{
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
  }

  return 0;
}
