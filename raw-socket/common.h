#ifndef __COMMON_H__
#define __COMMON_H__

#include "define.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>
#include <assert.h>

void updateCurrDir();
char *newString();
void concat(char *, char *);
char *listCurrentFiles(char *);

char CURR_DIR[PATH_MAX];

#endif
