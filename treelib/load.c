
#include "treelib.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires

void unload(Folder parent)
{
  unload(parent->subFolder);
  unload(parent->nextFolder);
  free(parent);
}

void load(Folder parent, string path)
{
  DIR *dp;
  struct dirent *dirp;

  if (path == NULL)
  {
    fprintf(stderr, "Usage: ./program directory_name\n");
    exit(EXIT_FAILURE);
  }
  strcpy(parent->path, path);
  int i = 0, j = 0;
  errno = 0;
  if ((dp = opendir(path)) != NULL)
  {
    Folder tmpFolder = NULL, folder;
    while ((dirp = readdir(dp)) != NULL)
    {
      i++;
      //printf("%d | %d\n", strcmp(dirp->d_name, "."), strcmp(dirp->d_name, ".."));
      //printf("while\n");
      if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0 && dirp->d_type == 4)
      {
        j++;
        //printf("if\n");
        folder = (Folder)malloc(sizeof(struct Element));
        //tmpFolder = (Folder)malloc(sizeof(struct Element));
        //printf("%s\n", subPath);
        //printf("%d | %s | %s | %d | %ld\n", dirp->d_type, path, dirp->d_name, dirp->d_reclen, dirp->d_off);

        string subPath;
        strcpy(subPath, path);
        strcat(subPath, "/");
        strcat(subPath, dirp->d_name);

        strcpy(folder->name, dirp->d_name);
        strcpy(folder->path, subPath);
        folder->nextFolder = tmpFolder;
        //printf("%s\n", folder->path);
        //printf("%s\n", folder->path);
        tmpFolder = folder;

        //if (strcmp(folder->path, "") != 0)
          load(folder, folder->path);
      }
      //printf("i = %d | j = %d | %s\n", i, j, dirp->d_name);
    }
    printf("folder-> path : %s\n", folder->path);
    parent->subFolder = folder;

    if (closedir(dp) == -1)
      perror("closedir");

    //exit(EXIT_SUCCESS);
  }
  /*
  else
  {
    switch (errno)
    {
    case EACCES:
      printf("Permission denied\n");
      //break;
    case ENOENT:
      printf("Directory does not exist\n");
      //break;
    case ENOTDIR:
      printf("'%s' is not a directory\n", path);
      //break;
    }
    //exit();
  }
  */
}