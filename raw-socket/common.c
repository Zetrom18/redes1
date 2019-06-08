#include "common.h"

void updateCurrDir(char *path) {
  // char cwd[PATH_MAX];
  // char* new_dir = concat(buffer, de->d_name);

  if (getcwd(path, sizeof(path)) != NULL) {
    concat(CURR_DIR, path);
  }else{
    puts("Nao foi possivel acessar diretorio");
  }
}

char* getCurrDir() {
  if (CURR_DIR == NULL)
    CURR_DIR[0] = '\0';

  return CURR_DIR;
}

char *newString(){
  char *str = (char *)malloc(sizeof(char));
  // assert(str);
  str[0] = '\0';
  return str;
}

void concat(char* str1, char* str2){
  str1 = (char *)realloc(str1,(strlen(str1)+strlen(str2)+1)*sizeof(char));
  strcat(str1,str2);
}

char *listCurrentFiles(char *dir_path) {
	struct dirent *de;

	DIR *dr = opendir(dir_path);
	// assert(dr);

  char *buffer = newString();

	while ((de = readdir(dr)) != NULL){
    concat(buffer, de->d_name);
    concat(buffer, " ");
  }

	closedir(dr);
	return buffer;
}