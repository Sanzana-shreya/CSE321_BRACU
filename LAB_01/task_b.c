#include <stdio.h>


int main() {
    FILE *fr, *fw;
    char c;
    int space_count = 0;


    fr = fopen("input_b.txt", "r");
    fw = fopen("output_b.txt", "w");


    if (fr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }


    while ((c = fgetc(fr)) != EOF) {
        if (c == ' ') {
            space_count++;
            if (space_count == 1) {
                fputc(c, fw);
            }
        }
        else {
            fputc(c, fw);
            space_count = 0;
        }
    }


    fclose(fr);
    fclose(fw);


    return 0;
}


