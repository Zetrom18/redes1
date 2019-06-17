#include "common.h"

char *newString(){
    char *str = (char *)malloc(sizeof(char));
    assert(str);
    str[0] = '\0';
    return str;
}


char *concat(char* str1, char* str2) {
    char *new_string = (char *) malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
    assert(new_string);
    new_string[0] = '\0';
    strcat(new_string, str1);
    strcat(new_string, str2);
    free(str1);

    return new_string;
}

void updateCurrDir(char *path) {
    char* buffer = newString();
    if (path[0]=='/') {
        buffer = concat(buffer, path);
    } else {
        buffer = concat(buffer, CURR_DIR);
        buffer = concat(buffer, "/");
        buffer = concat(buffer, path);
    }

    if (listCurrentFiles(buffer, NULL, true)) {
        strcpy(CURR_DIR, buffer);
    }
    free(buffer);
}

char *listCurrentFiles(char *dir_path, char *opt, bool fake) {
    struct dirent *de;

    DIR *dr = opendir(dir_path);
    if (!dr) {
        return "Nao foi possivel acessar diretorio";
    }

    if (fake){
        return "";
    }

    char *buffer = newString();
    char separator[2];
    bool hidden = false;
    if (opt && (opt[0]=='a' || opt[1]=='a')){
        hidden = true;
    }
    if (opt && (opt[0]=='l' || opt[1]=='l')) {
        strcpy(separator,"\n");
    } else {
        strcpy(separator," ");
    }

    while ((de = readdir(dr)) != NULL) {
        if (hidden || de->d_name[0]!='.') {
            buffer = concat(buffer, de->d_name);
            buffer = concat(buffer, separator);
        }
    }

    if (separator[0] == '\n') {
        buffer[strlen(buffer)-1] = '\0';
    }

    closedir(dr);
    return buffer;
}

void appendChar(char *str, char c){
    char aux[2];
    aux[0] = c;
    aux[1] = '\0';
    concat(str, aux);
}

void clearCommands(char **cg){
    free(cg[1]);
    free(cg[0]);
    cg[0] = newString();
    cg[1] = newString();
}

void showbits(unsigned int x) {
    for(int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}
