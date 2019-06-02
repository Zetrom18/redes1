#include "common.h"

void updateCurrDir() {
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    strcpy(CURR_DIR, cwd);
  }else{
    puts("Nao foi possivel acessar diretorio");
  }
}

char *listCurrentFiles(char *dir_path) {
	struct dirent *de;

	DIR *dr = opendir(dir_path);
	assert(dr);

  char *buffer = (char *)malloc(sizeof(char));
  assert(buffer);
  buffer[0] = '\0';

	while ((de = readdir(dr)) != NULL){
    buffer = (char *)realloc(buffer,(strlen(buffer)+strlen(de->d_name)+2)*sizeof(char));
    strcat(buffer, de->d_name);
    strcat(buffer, "\n");
  }

	closedir(dr);
	return buffer;
}
