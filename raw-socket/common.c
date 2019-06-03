#include "common.h"

void updateCurrDir() {
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    strcpy(CURR_DIR, cwd);
  }else{
    puts("Nao foi possivel acessar diretorio");
  }
}

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

char *listCurrentFiles(char *dir_path) {
	struct dirent *de;

	DIR *dr = opendir(dir_path);
	assert(dr);

  char *buffer = newString();

	while ((de = readdir(dr)) != NULL){
    concat(buffer, de->d_name);
    concat(buffer, " ");
  }

	closedir(dr);
	return buffer;
}
