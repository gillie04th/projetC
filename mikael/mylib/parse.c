#include <stdio.h>
#include <string.h>
#include "treelib.h"

int parse(const char *src, char *v1, char *v2){        //parse un fichier
        if (sscanf(src,"%[^= ] = %[^=]", v1, v2) == 2)
            return 1;
        else
            return 0;

}
