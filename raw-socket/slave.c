#include "slave.h"

void test(){
  puts(ls("", "l"));
  cd("my-test-dir");
  puts(ls(".", NULL));
  cd("failed-dir");
  puts(ls("/home", "a"));
  mount_messages("hahaha");
}

char *ls(char *dir, char *opt){
  char *directory_list;
  if (strcmp(dir,"")==0){
    directory_list = listCurrentFiles(CURR_DIR, opt, false);
  } else if (dir[0]=='/'){
    directory_list = listCurrentFiles(dir, opt, false);
  } else {
    char* buffer = newString();
    concat(buffer, CURR_DIR);
    concat(buffer, "/");
    concat(buffer, dir);
    directory_list = listCurrentFiles(buffer, opt, false);
    free(buffer);
  }
  return directory_list;
}

char *cd(char *path){
  updateCurrDir(path);
}

void init() {
  CURR_DIR[0] = '.';
  CURR_DIR[1] = '\0';
  puts("Inicializando escravo...");
  ConexaoRawSocket(ADDR);
  test();
  puts("Escravo inicializado com sucesso");
  controller();
}

void controller(){
  while (true) {
    /* code */
  }
}

int main(int argc, char const *argv[]) {
  init();
  controller();
  return 0;
}
