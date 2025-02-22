#include <stdio.h>

int main(){
    int a,b;

    printf("Enter the First Number:",a);
    scanf("%d",&a);
    printf("Enter the Second Number:",b);
    scanf("%d",&b);

    if (a>b){
        int result_01 = a - b ;
        printf("Subtraction is:%d",result_01);
    }
    else if (a<b){
        int result_02 = a + b ;
        printf("Addition is:%d",result_02);
    }
    else{
        int result_03 = a * b ;
        printf("Multiplication is:%d",result_03);
    }
    return 0;
    
}
