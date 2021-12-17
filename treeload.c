#include "treelib/treelib.h"
#include <stdio.h>
#include <signal.h>

// Initialisation des variables
Folder TREE;
string confFile = "tree.conf", pidFile, dataFile, rootDir;

void treesearch()
{
    string data;
    loadConf(confFile, &dataFile, "datafile");
    readText(dataFile, &data);
    //printf("%s\n", data);
    printf("Recherche de %s dans l'arborescence :\n", data);
    search(TREE, data);
    //printf("Erreur de chargement du répertoire");
    //printf("treesearch\n");
    printf("Attente de l'instructin suivante ...\n");
}

void treeload()
{
    if (TREE == NULL)
    {
        // Chargement des données dans le fichier de configuration
        loadConf(confFile, &rootDir, "rootdir");
        // Allocation de mémoire pour le répertoire racine
        TREE = (Folder)malloc(sizeof(struct Element));
        // Affectation du chemin au répertoire racine
        strcpy(TREE->path, rootDir);
        // Chargement de l'arbre en mémoire
        load(TREE, TREE->path);
        /**/
        //printf("treeload\n");
    }
    treesearch();
}

void treeunload()
{
    printf("Fermeture de treeload\n");
    unload(TREE);
    //printf("treeunload\n");
    
    exit(0);
}

void setPid()
{
    pid_t pid = getpid();
    loadConf(confFile, &pidFile, "pidfile");
    writeInt(pidFile, pid);
    //printf("setPid\n");
}

int main()
{
    setPid();
    printf("Attente du signal ...\n");

    signal(SIGUSR1, treeunload);
    signal(SIGHUP, treeload);

    for (;;)
        ;

    return 0;
}
