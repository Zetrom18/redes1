#include "master.h"

void lls(){
  printf("%s", listCurrentFiles(CURR_DIR));
}

void init() {
  CURR_DIR[0] = '\0';
  updateCurrDir();
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
