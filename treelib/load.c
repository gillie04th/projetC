
#include "treelib.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires

void load(Tree parent, string path)
{
  DIR *dp;
  struct dirent *dirp;

  if (path == NULL)
  {
    fprintf(stderr, "Usage: ./program directory_name\n");
    exit(EXIT_FAILURE);
  }

  errno = 0;
  if ((dp = opendir(path)) == NULL)
  {
    switch (errno)
    {
    case EACCES:
      printf("Permission denied\n");
      break;
    case ENOENT:
      printf("Directory does not exist\n");
      break;
    case ENOTDIR:
      printf("'%s' is not a directory\n", path);
      break;
    }
    exit(EXIT_FAILURE);
  }

  Folder tmpFolder, folder;
  folder = (Folder)malloc(sizeof(struct Element));
  while ((dirp = readdir(dp)) != NULL)
  {
    if (dirp->d_name != NULL)
    {
      tmpFolder = (Folder)malloc(sizeof(struct Element));
      parent->Folders = tmpFolder;
      tmpFolder->parent = parent;
      strcpy(tmpFolder->name, dirp->d_name);
      strcpy(tmpFolder->path, path);

      tmpFolder->nextFolder = folder;
      //printf("%s\n", folder->nextFolder->name);
      folder = tmpFolder;
    }
  }
  free(tmpFolder);

  if (closedir(dp) == -1)
    perror("closedir");

  //exit(EXIT_SUCCESS);
}

/*
int main()
{
  string folder;
  scanf("%c", folder);

  load(folder);

  return 1;
}
*/