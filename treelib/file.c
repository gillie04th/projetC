#include "treelib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int isFile(string path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int isDirectory(string path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}