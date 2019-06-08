#include "common.h"

char *newString(){
  char *str = (char *)malloc(sizeof(char));
  assert(str);
  str[0] = '\0';
  return str;
}

void concat(char* str1, char* str2){
  str1 = (char *)realloc(str1,(strlen(str1)+strlen(str2)+1)*sizeof(char));
  assert(str1);
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

  if (listCurrentFiles(buffer, NULL, true)) {
    strcpy(CURR_DIR, buffer);
  }
  free(buffer);
}

char *listCurrentFiles(char *dir_path, char *opt, bool fake) {
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
  char separator[2];
  bool hidden = false;
  if (opt && (opt[0]=='a' || opt[1]=='a')){
    hidden = true;
  }
  if (opt && (opt[0]=='l' || opt[1]=='l')){
    strcpy(separator,"\n");
  } else {
    strcpy(separator," ");
  }

	while ((de = readdir(dr)) != NULL){
    if (hidden || de->d_name[0]!='.'){
      concat(buffer, de->d_name);
      concat(buffer, separator);
    }
  }

	closedir(dr);
	return buffer;
}
