#include "master.h"
#include <unistd.h>

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
  puts("Mestre inicializado com sucesso");
  controller(socket);
}

void help(){
  puts("SOON TO BE");
}

unsigned char *bin_array_to_bytes(int *bin_array, int size){
	int i,j=0;
  unsigned char *bytes = (unsigned char*)malloc(sizeof(unsigned char)*(14));
	memset(bytes, 0, sizeof(bytes));
	for(i=0; i<size; i++){
    if((i+1) % 8 == 0){
      j++;
    }
    bytes[j] = (bytes[j] | (bin_array[i]==1 ? 1u : 0u)) << 1;
	}
	return bytes;
}

void controller(int socket){
  // char c;
  // int c_count = 0;
  // char *commandGroup[2];
  // commandGroup[c_count] = newString();
  int **messages = mount_data_messages("Qualquer coisa ble bla bla");
  // mount_data_messages(listCurrentFiles(".", "", false));

  puts("wfbuice");
  int *message =  messages[0];
  int *array = message;
  // int array[] = {0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0};
  for(int i=0; i<96; i++){
    printf("%d\n", messages[0][i]);
  }
  unsigned char *bytes = bin_array_to_bytes(array, 96);
  int count = 0;
  while (true) {
    puts("while start");
    ssize_t sent_count = send(socket, bytes, 14, 0);
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
