#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errExit.h>
#include <unistd.h>
#include "string.h"

int main(int argc, char *argv[]) {
    printf("Hi, I'm Salva program!\n");

    char *fileName = argv[1];

    int fd = open(fileName, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open");
    // A buffer collecting the string

    printf("opened %s", fileName);


    const int MAX_BUF = 1000;
    char buffer[MAX_BUF];

    int length = 0;


    for(int i=3; i<argc; i++){
        length += snprintf(buffer+length, MAX_BUF-length, "%s", argv[i]);
        length += snprintf(buffer+length, MAX_BUF-length, " ");
    }

    // writing up to sizeof(buffer) bytes into myfile
    ssize_t numWrite = write(fd, buffer, length);
    if (numWrite != length)
        errExit("write");


    return 0;
}
