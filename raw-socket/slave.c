#include "slave.h"

void init() {
  CURR_DIR[0] = '\0';
  updateCurrDir();
  // ConexaoRawSocket(ADDR);
  puts("Escravo inicializado com sucesso");
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
