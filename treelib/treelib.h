#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>  
#include <dirent.h>
#include <errno.h>

typedef char string[PATH_MAX];

struct Element
{
  //struct Node *parent;
  struct Element *nextFolder;
  struct Element *subFolder;
  string path;
  string name;
};
typedef struct Element * Folder;

/*
struct Node
{
  struct Element *Folders;
};
typedef struct Node * Tree;
*/

int search(Folder folder, string dirName);
void load(Folder parent, string path);
void unload(Folder parent);
void displayTree(Folder folder);
void loadConf(string configFile, string *rootdir);
int isFile(string path);
int isDirectory(string path);
int isSymlink(string filename);
int parse(const char *src, char *v1, char *v2);