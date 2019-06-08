#include "master.h"

void lls(){
  puts(listCurrentFiles(getCurrDir()));
}

void lcd(char* path){
  updateCurrDir(path);
}

void init() {
  puts("Inicializando mestre...");
  lls();
  lcd("my-test-dir");
  lls();
  // ConexaoRawSocket(ADDR);
  puts("Mestre inicializado com sucesso");
}

void controller(){
  while (TRUE) {
    /* code */
  }
}

int main(int argc, char const *argv[]) {
  init();
  controller();
  return 0;
}
