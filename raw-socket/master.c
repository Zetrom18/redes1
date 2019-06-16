#include "master.h"

void test_ls_cd(){
  lcd("my-test-dir");
  lls(".", NULL);
  lcd("failed-dir");
  lls("/home", "al");
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
  int socket;
  test_ls_cd();
  test();
  CURR_DIR[0] = '.';
  CURR_DIR[1] = '\0';
  puts("Inicializando mestre...");
  socket = ConexaoRawSocket(ADDR);
  puts("Mestre inicializado com sucesso");
  controller(socket);
}

void help(){
  puts("SOON TO BE");
}

void controller(int socket){
  // char c;
  // int c_count = 0;
  // char *commandGroup[2];
  // commandGroup[c_count] = newString();
  char *str = "1";
  while (true) {
    puts("while start");
    send(socket, str, sizeof(str), 0);
    puts("while end");
    // c = getchar();
    // if (c_count == 0 && c == ' '){
    //   c_count++;
    //   commandGroup[c_count] = newString();
    // } else if (c == '\n'){
    //   if (false) {
    //     /* code */
    //   } else if (false) {
    //     /* code */
    //   } else {
    //     help();
    //   }
    //   clearCommands(commandGroup);
    //   c_count = 0;
    // } else {
    //   appendChar(commandGroup[c_count], c);
    // }
  }
}

int main(int argc, char const *argv[]) {
  init();
  return 0;
}
