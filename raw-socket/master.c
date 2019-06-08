#include "master.h"

void test(){
  lls("");
}

void lls(char *dir){
  if(strcmp(dir,"")==0){
    puts(listCurrentFiles(CURR_DIR));
  }else{
    
  }
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
