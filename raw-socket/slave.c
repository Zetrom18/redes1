#include "slave.h"

void test(){
  puts(ls("", "l"));
  cd("my-test-dir");
  puts(ls(".", NULL));
  cd("failed-dir");
  puts(ls("/home", "a"));
  mount_data_messages("hahaha");
}

char *ls(char *dir, char *opt){
  char *directory_list;
  if (strcmp(dir,"")==0){
    directory_list = listCurrentFiles(CURR_DIR, opt, false);
  } else if (dir[0]=='/'){
    directory_list = listCurrentFiles(dir, opt, false);
  } else {
    char* buffer = newString();
    concat(buffer, CURR_DIR);
    concat(buffer, "/");
    concat(buffer, dir);
    directory_list = listCurrentFiles(buffer, opt, false);
    free(buffer);
  }
  return directory_list;
}

char *cd(char *path){
  updateCurrDir(path);
}

void init() {
  int socket;
  CURR_DIR[0] = '.';
  CURR_DIR[1] = '\0';
  puts("Inicializando escravo...");
  socket = ConexaoRawSocket(ADDR);
  // test();
  puts("Escravo inicializado com sucesso");
  controller(socket);
}

void controller(int socket) {
  unsigned char buffer[MAX_BYTE_COUNT];
  int count = 0;
  int i, len = 0;
  int size, sequence, type, data_size;
  int *data, *bin_array;
  while (true) {
    memset(&buffer, 0, sizeof(buffer));
    len = recv(socket, &buffer, sizeof(buffer), 0);
    if(len > 0){
      count++;
      printf("\nMessage %d (size %d):\n", count, len);
      for(i=0; i<len; i++){
        showbits(buffer[i]);
        printf(" ");
      }
      bin_array = bytes_to_bin_array(buffer, MAX_BYTE_COUNT);
      if(parse_message(bin_array, &size, &sequence, &type, &data_size, data)){
        printf("\nMessage number: %d\n\tsize: %d\n\tsequence: %d\n\ttype: %d\n\tdata_size: %d\n\tData: %s\n\t", count, size, sequence, type, data_size, get_string(data; 0, data_size));
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  init();
  return 0;
}
