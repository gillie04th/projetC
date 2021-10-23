/*
Ecrire 2 fonctions : load qui charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires, et search qui localise les occurrences d’une entrée donnée (dont le nom est fourni en argument) dans la structure de données précédente.

Créer une bibliothèque contenant ces 2 fonctions (et éventuellement d’autres fonctions ayant un potentiel de réutilisation).

/////////////////////
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
#include "mylib/treelib.h"

#define ORIGINAL "tree.conf" //sans commentaire ou ligne blance
#define L 60

void treetest(char filename){

}

int main()
{
  FILE *in;
  char s[L], s2[L], s3[L];
 // int nl = 0 ;

  in = fopen(ORIGINAL,"r") ; // fopen permet l'ouverture d'un fichier de données qui se fait via le type FILE *
  if (in==NULL) { perror(ORIGINAL) ; return 1 ; }
  
 
  while(fgets(s,L-1,in)!=NULL) // fgets permet la lecture d'un fichier de données qui se fait via le type FILE *
  {
    s[strlen(s)-1]='\0';
    if(parse(s, s2, s3))
      printf("%s %s \n", s2, s3);
  
  }
 // treetest(argv[1]);
  fclose(in) ; //permet la fermeture d'un fichier de données qui se fait via le type FILE *
  return 0; 
}
