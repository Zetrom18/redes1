#include "master.h"

void test(){
  lls("", "l");
  lcd("my-test-dir");
  lls(".", NULL);
  lcd("failed-dir");
  lls("/home", "al");
  mount_messages("hahaha");
}

void lls(char *dir, char *opt){
  if (strcmp(dir,"")==0){
    puts(listCurrentFiles(CURR_DIR, opt, false));
  } else if (dir[0]=='/'){
    puts(listCurrentFiles(dir, opt, false));
  } else {
    char* buffer = newString();
    concat(buffer, CURR_DIR);
    concat(buffer, "/");
    concat(buffer, dir);
    puts(listCurrentFiles(buffer, opt, false));
    free(buffer);
  }
}

void lcd(char *path){
  updateCurrDir(path);
}

void init() {
  CURR_DIR[0] = '.';
  CURR_DIR[1] = '\0';
  puts("Inicializando mestre...");
  // ConexaoRawSocket(ADDR);
  test();
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
