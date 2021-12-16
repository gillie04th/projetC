#include "treelib/treelib.h"
#include <stdio.h>
#include <signal.h>

// Initialisation des variables
Folder TREE;
string confFile = "tree.conf", pidFile, rootDir;

void treesearch()
{
    string dataFile;
    loadConf(confFile, &dataFile, "datafile");
    if (TREE != NULL)
        search(TREE, dataFile);
    else
        printf("Erreur de chargement du répertoire");
    printf("treesearch\n");
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
        /*
        // Chargement de l'arbre en mémoire
        load(TREE, TREE->path);
        /**/
        printf("treeload\n");
    }
    treesearch();
}

void treeunload()
{
    //unload(TREE);
    printf("treeunload\n");
    exit(0);
}

void setPid(){
    pid_t pid = getpid();
    loadConf(confFile, &pidFile, "pidfile");
    writeInt(pidFile, pid);
    printf("setPid\n");
}

int main()
{
    setPid();

    signal(SIGHUP, treeload);
    signal(SIGTERM, treeunload);

    for (;;)
        ;

    return 0;
}
