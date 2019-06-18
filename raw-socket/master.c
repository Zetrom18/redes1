#include "master.h"
#include <unistd.h>

void test_ls_cd(){
  lcd("my-test-dir");
  lls(".", NULL);
  lcd("failed-dir");
  lls("/home", "al");
}

void test() {
    mount_data_messages(listCurrentFiles(".", "", true));
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
//  test_ls_cd();
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
  // char str[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
  // int str[] = {1,2,3,4,5,6,7,8,9};
  unsigned short int str[] = {255, 255, 255, 0, 0, 0, 0, 7, 7, 7, 7 ,7, 7, 6};
  int count = 0;
  while (true) {
    puts("while start");
    ssize_t sent_count = send(socket, str, sizeof(str), 0);
    if (sent_count < 0){
      perror("send() error");
      exit(-1);
    }
    printf("%d\n", sent_count);
    count++;
    printf("Sent %d\n", count);
    puts("while end");
    sleep(10);
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
