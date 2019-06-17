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
#include "messenger.h"
#include "crs.h"

char *newString();
char *concat(char* str1, char* str2);
void updateCurrDir(char *path);
char *listCurrentFiles(char *, char *, bool);
void appendChar(char *, char);
void clearCommands(char **);
void showbits(unsigned int);

char CURR_DIR[PATH_MAX];

#endif
