#include "common.h"

char *newString(){
  char *str = (char *)malloc(sizeof(char));
  assert(str);
  str[0] = '\0';
  return str;
}

void concat(char* str1, char* str2){
  str1 = (char *)realloc(str1,(strlen(str1)+strlen(str2)+1)*sizeof(char));
  strcat(str1,str2);
}

void updateCurrDir(char *path) {
  char* buffer = newString();
  if (path[0]=='/') {
    concat(buffer, path);
  } else {
    concat(buffer, CURR_DIR);
    concat(buffer, "/");
    concat(buffer, path);
  }

  if (listCurrentFiles(buffer, true)) {
    strcpy(CURR_DIR, buffer);
  }
  free(buffer);
}

char *listCurrentFiles(char *dir_path, bool fake) {
	struct dirent *de;

	DIR *dr = opendir(dir_path);
  if (!dr) {
    puts("Nao foi possivel acessar diretorio");
    return NULL;
  }

  if (fake){
    return "\0";
  }

  char *buffer = newString();

	while ((de = readdir(dr)) != NULL){
    concat(buffer, de->d_name);
    concat(buffer, " ");
  }

	closedir(dr);
	return buffer;
}
