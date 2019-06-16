#include "master.h"

void test_ls_cd(){
  lls("", "");
  lls("", "");
  lls("", "");
  lls("", "");
  lls("", "");
  lls("", "");
  lls("", "");
  lls("", "");
  lcd("my-test-dir");
  lls(".", NULL);
  lcd("failed-dir");
  lls("/home", "al");
  lcd(".");
  lcd(".");
  lcd(".");
  lcd(".");
  lcd(".");
  lcd(".");
  lcd(".");
  // mount_messages("hahaha");
}

void test() {
   mount_messages(listCurrentFiles(".", "", false));
}

void lls(char *dir, char *opt){
  if (strcmp(dir,"")==0){
    puts(listCurrentFiles(CURR_DIR, opt, false));
  } else if (dir[0]=='/'){
    puts(listCurrentFiles(dir, opt, false));
  } else {
    char* buffer = newString();
    buffer = concat(buffer, CURR_DIR);
    buffer = concat(buffer, "/");
    buffer = concat(buffer, dir);
    puts(listCurrentFiles(buffer, opt, false));
    free(buffer);
  }
}

void lcd(char *path){
  updateCurrDir(path);
}

void init() {
  test();
  CURR_DIR[0] = '.';
  CURR_DIR[1] = '\0';
  puts("Inicializando mestre...");
  // ConexaoRawSocket(ADDR);
  puts("Mestre inicializado com sucesso");
  controller();
}

void help(){
  puts("SOON TO BE");
}

void controller(){
  char c;
  int c_count = 0;
  char *commandGroup[2];
  commandGroup[c_count] = newString();
  while (true) {
    c = getchar();
    if (c_count == 0 && c == ' '){
      c_count++;
      commandGroup[c_count] = newString();
    } else if (c == '\n'){
      if (false) {
        /* code */
      } else if (false) {
        /* code */
      } else {
        help();
      }
      clearCommands(commandGroup);
      c_count = 0;
    } else {
      appendChar(commandGroup[c_count], c);
    }
  }
}

int main(int argc, char const *argv[]) {
  init();
  controller();
  return 0;
}
