#ifndef __COMMON_H__
#define __COMMON_H__

#include "crs.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>

void reallocString(char *, int);
void updateCurrDir();
char *listCurrentFiles(char *);

char CURR_DIR[PATH_MAX];

#endif
