#include "treelib/treelib.h"
#include <stdio.h>
#include <signal.h>

Folder TREE;

void writeText(string filename, string text)
{
    // Ouvre le fichier dans lequel écrire
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("%s doit être créer", filename);
    }
    // Ecrit le texte dans le fichier
    fprintf(fp, "%s\n", text);

    // close the file
    fclose(fp);
}

void writeInt(string filename, int number)
{
    // Ouvre le fichier dans lequel écrire
    FILE *fp = fopen(filename, "w");
    printf("writeInt\n");
    if (fp == NULL)
    {
        printf("%s doit être créer\n", filename);
    }else{
    // Ecrit le texte dans le fichier
    fprintf(fp, "%d\n", number);

    // close the file
    fclose(fp);
    }
}

void treeload(int s)
{
    pid_t pid = getpid();

    // Initialisation des variables
    string confFile = "tree.conf", rootDir, dataFile, pidFile;
    // Chargement des données dans le fichier de configuration
    loadConf(confFile, &rootDir, "rootdir");
    loadConf(confFile, &dataFile, "datafile");
    loadConf(confFile, &pidFile, "pidfile");
    /*
    // Allocation de mémoire pour le répertoire racine
    TREE = (Folder)malloc(sizeof(struct Element));
    // Affectation du chemin au répertoire racine
    strcpy(TREE->path, rootPath);
    // Chargement de l'arbre en mémoire
    load(TREE, TREE->path);
    /**/
    writeInt(pidFile, pid);

    //printf("Signal %d bien recu\n", s);
}

void treeunload(int s)
{
    //unload(TREE);
    printf("Signal %d bien recu\n", s);
}

int main()
{
    signal(SIGHUP, treeload);
    signal(SIGTERM, treeunload);

    for (;;)
        ;

    return 0;
}
