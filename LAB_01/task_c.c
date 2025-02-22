#include <stdio.h>


int main(){
    char password[20];
    scanf("%s", password);
    int counter = 0;
    int lower_case = 0, upper_case = 0, digit = 0, special = 0;


    for (int i = 0; password[i] != '\0'; i++){
        if (password[i] >= 'a' && password[i] <= 'z'){
            lower_case++;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z'){
            upper_case++;
        }
        else if (password[i] >= '0' && password[i] <= '9'){
            digit++;
        }
        else if (password[i] == '_' || password[i] == '$' || password[i] == '#' || password[i] == '@'){
            special++;
        }
    }





    if (lower_case == 0){
        counter++;
        if (counter == 1){
            printf("Lowercase character missing");
        }
        else{
            printf(", Lowercase character missing");
        }
    }


    if (upper_case == 0){
        counter++;
        if (counter == 1){
            printf("Uppercase character missing");
              }
        else{
            printf(", Uppercase character missing");
        }
    }


    if (digit == 0){
        counter++;
        if (counter == 1){
            printf("Digit missing");
        }
        else{
            printf(", Digit missing");
        }
    }


    if (special == 0){
        counter++;
        if (counter == 1){
            printf("Special character missing");
        }
        else{
            printf(", Special character missing");
        }
    }


    if (counter == 0){
        printf("OK");
    }
    
    return 0;
}




