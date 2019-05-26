#include "main.h"

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    puts("Parametros insuficientes");
    exit(-1);
  }
  if (strcmp("m", argv[1])==0) {
    puts("Sou master");
    initMaster();
  }else if (strcmp("s", argv[1])==0) {
    puts("Sou slave");
    initSlave();
  }else{
    puts("Parametros incorretos");
    exit(-1);
  }
  return 0;
}