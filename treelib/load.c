
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
  Folder tmpFolder, folder;

  if (path == NULL)
  {
    fprintf(stderr, "Usage: ./program directory_name\n");
    exit(EXIT_FAILURE);
  }
  strcpy(parent->path, path);

  errno = 0;
  if ((dp = opendir(path)) != NULL)
  {
    while ((dirp = readdir(dp)) != NULL)
    {
      printf("%s\n", dirp->d_name);
      //printf("while\n");
      if (strcmp(dirp->d_name, "/") != 0 && strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0 && dirp->d_type == 4)
      {
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
        if (tmpFolder == NULL)
        {
          folder->nextFolder = NULL;
        }
        else
        {
          folder->nextFolder = tmpFolder;
        }
        //printf("%s\n", folder->path);
        //printf("%s\n", dirp->d_name);
        tmpFolder = folder;

        if (strcmp(folder->path, "") != 0)
          //load(folder, folder->path);

          parent->subFolder = folder;
      }
      printf("%s | %s\n", folder->path, tmpFolder->path);
    }

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
  /**/
}