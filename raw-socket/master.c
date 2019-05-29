#include "master.h"

void init() {
  CURR_DIR[0] = '\0';
  updateCurrDir();
  puts(listCurrentFiles(CURR_DIR));
  // ConexaoRawSocket(ADDR);
  while (1==1) {
    /* code */
  }
}

int main(int argc, char const *argv[]) {
  init();
  return 0;
}
