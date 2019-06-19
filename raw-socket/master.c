#include "master.h"
#include <unistd.h>

void await_ack(int socket);

void test_ls_cd(){
  lcd("my-test-dir");
  lls(".", NULL);
  lcd("failed-dir");
  lls("/home", "al");
}

void test() {
    // mount_data_messages(listCurrentFiles(".", "", true));
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
//  puts("Mestre inicializado com sucesso");
  controller(socket);
}

void help(){
  puts("SOON TO BE");
}

void send_message(int socket, int *message, int sequence){
  fill_sequence(message, sequence);
  int *array = message;
  unsigned char *bytes = bin_array_to_bytes(array, MAX_MESSAGE_BIT_COUNT);
  int count = 0;

  puts("sending message...");
  ssize_t sent_count = send(socket, bytes, MAX_BYTE_COUNT, 0);
  if (sent_count < 0){
    perror("send() error");
    exit(-1);
  }
//  printf("%d\n", sent_count);
//  count++;
//  printf("Sent %d\n", count);
  puts("message sent");
}

void send_ls(int socket, char *params) {
  int **message = mount_data_messages(params, LS);
  send_message(socket, message[0], 0);
  await_ack(socket);
}

void await_ack(int socket) {

}

void send_cd(){

}

void controller(int socket){
   char c;
   int c_count = 0;
   char *commandGroup[2];
   commandGroup[c_count] = newString();
  int **messages = mount_data_messages(listCurrentFiles(".", "", false), DATA);

  int *message =  messages[0];
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
    send_message(socket, message);
  }

}

int main(int argc, char const *argv[]) {
  init();
  return 0;
}
