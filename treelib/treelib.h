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
#include <readline/readline.h>
#include <readline/history.h>

#define VRAI 1
#define FAUX 0
#define NSTRING 256

typedef char string[NSTRING];

struct Element
{
  struct Node *parent;
  struct Element *nextFolder;
  char * path[PATH_MAX];
  char * name[FILENAME_MAX];
};
typedef struct Element * Folder;

struct Node
{
  struct Element *Folders;
};
typedef struct Node * Tree;

int isFile(string path);

int isDirectory(string path);

int search();

int load(Tree *n,string path);

int parse(const char *src, char *v1, char *v2);