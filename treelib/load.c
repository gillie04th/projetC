
#include "treelib.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires

void unload(Folder parent)
{
  if (parent != NULL)
  {
    //printf("start");
    unload(parent->subFolder);
    //printf("sub->next");
    unload(parent->nextFolder);
    //printf("next->end");
    free(parent);
    //printf("end");
  }
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
  errno = 0;

  if ((dp = opendir(path)) != NULL)
  {
    Folder tmpFolder = NULL, folder;
    string subPath;
    while ((dirp = readdir(dp)) != NULL)
    {
      if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0 && dirp->d_type == 4)
      {
        folder = (Folder)malloc(sizeof(struct Element));
        folder->subFolder = NULL;

        strcpy(subPath, path);
        strcat(subPath, "/");
        strcat(subPath, dirp->d_name);
        strcpy(folder->path, subPath);
        strcpy(folder->name, dirp->d_name);
        folder->nextFolder = tmpFolder;
        tmpFolder = folder;

        //printf("%s\n", folder->path);
        load(folder, folder->path);
      }
    }

    if (closedir(dp) == -1)
      perror("closedir");

    //exit(EXIT_SUCCESS);
    parent->subFolder = folder;
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