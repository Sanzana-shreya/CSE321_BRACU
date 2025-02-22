#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {


    int i, num;
    for (i = 1; i < argc; i++) {
        num = atoi(argv[i]);
        if (num % 2 == 0) {
            printf("%d is Even.\n", num);
        } else {
            printf("%d is Odd.\n", num);
        }
    }


    return 0;
}






