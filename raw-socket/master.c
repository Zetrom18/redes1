#include "master.h"

void test(){
  // lls("");
  // lcd("my-test-dir");
  // lls("");
  // lcd("failed-dir");
  mount_messages("hahaha");
}

void lls(char *dir){
  if (strcmp(dir,"")==0){
    puts(listCurrentFiles(CURR_DIR, false));
  } else if (dir[0]=='/'){
    puts(listCurrentFiles(dir, false));
  } else {
    char* buffer = newString();
    concat(buffer, CURR_DIR);
    concat(buffer, "/");
    concat(buffer, dir);
    puts(listCurrentFiles(buffer, false));
    free(buffer);
  }
}

void lcd(char* path){
  updateCurrDir(path);
}

void init() {
  CURR_DIR[0] = '.';
  CURR_DIR[1] = '\0';
  puts("Inicializando mestre...");
  test();
  // ConexaoRawSocket(ADDR);
  puts("Mestre inicializado com sucesso");
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
