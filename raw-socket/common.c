#include "common.h"

void reallocString(char *str, int size){
  printf("%s\n", str);
  str = (char *)realloc(str, (size)*sizeof(char));
}

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

	if (dr == NULL) {
		return "ERROR";
	}

  char *buffer = "";
	while ((de = readdir(dr)) != NULL){
    printf("%d %d\n", strlen(buffer), strlen(de->d_name));
    printf("%s %s\n", buffer, de->d_name);
    buffer = (char *)realloc(buffer,(strlen(buffer)+strlen(de->d_name)+2)*sizeof(char));
    strcat(buffer, de->d_name);
    strcat(buffer, "\n");
    puts(buffer);
  }

	closedir(dr);
	return buffer;
}
