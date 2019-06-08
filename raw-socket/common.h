#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>
#include <assert.h>

char *newString();
void concat(char *, char *);
void updateCurrDir(char *path);
char *listCurrentFiles(char *, bool);

char CURR_DIR[PATH_MAX];

#endif
