#include "treelib/treelib.h"
#include <stdio.h>
#include <signal.h>

// Initialisation des variables
Folder TREE;
string confFile = "tree.conf", pidFile, dataFile, rootDir;

// Fonction de recherche dans l'arborescence
void treesearch()
{
    string data;
    // Charge le chemin du ficier contenant le nom du répertoire à trouver 
    loadConf(confFile, &dataFile, "datafile");
    readText(dataFile, &data);
    printf("Recherche de %s dans l'arborescence :\n", data);
    // Recherche dans l'arborescence
    search(TREE, data);
    printf("Attente de l'instructin suivante ...\n");
}

// Fonction de chargement de l'arborescence en mémoire
void treeload()
{
    // Si l'arbre est vide on charge l'arboescence en mémoire
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
    }
    // Une fois le chargement effectué, on lance la fonction de recherche du fichier
    treesearch();
}

// Fonction de déchargement de la mémoire
void treeunload()
{
    printf("Fermeture de treeload\n");
    // Déchargement de la mémoire
    unload(TREE);
    sleep(3);
    
    exit(0);
}

// Fonction d'écriture du pid dans le fichier préciser dans le fichier de configuration
void setPid()
{
    // Récupération du pid
    pid_t pid = getpid();
    // Chargement du chemin du fichier devant contenir le pid
    loadConf(confFile, &pidFile, "pidfile");
    // Ecriture du pid dans le fichier
    writeInt(pidFile, pid);
}

// Fonction de lancement du programme
int main()
{
    // Enregistrement du pid
    setPid();
    printf("Attente du signal ...\n");

    // Attente de signaux de la part du second programme
    signal(SIGUSR1, treeunload);
    signal(SIGHUP, treeload);

    for (;;)
        ;

    return 0;
}
