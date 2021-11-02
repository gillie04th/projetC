#include "treelib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Test si un chemin est un fichier
int isFile(string path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
// Test si un chemin est un dossier
int isDirectory(string path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}
// Test si un chemin est un lien symbolique
int isSymlink(string filename)
{
    struct stat p_statbuf;

    if (lstat(filename, &p_statbuf) < 0) {  /* if error occured */
        perror("calling stat()");
        exit(1);  /* end progam here */
    }

    if (S_ISLNK(p_statbuf.st_mode) == 1) {
        return 1;
    } else {
        return 0;
    }
}