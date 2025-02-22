#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>




int main(int argc, char *argv[]) {
   
    int fd;
    int MAX_LENGTH = 100;
    char buff[MAX_LENGTH];
    char input[MAX_LENGTH];
   
    if (argc != 2) {
        printf("Give just one argument for file.\n");
        exit(1);
    }
   
    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
   
    if (fd == -1) {
        printf("Error: Failed to open file %s\n", argv[1]);
        exit(1);
    }
   
    printf("Enter the input.\n");
   
    while (1) {
        fgets(input, MAX_LENGTH, stdin);
        if (strcmp(input, "-1\n") == 0) {
            break;
        }
        write(fd, input, strlen(input));
    }
   
    printf("Writing done, Start reading\n");
   
    lseek(fd, 0, SEEK_SET);
    while (read(fd, buff, MAX_LENGTH) > 0) {
        printf("%s", buff);
    }
   
    close(fd);


    return 0;
}









