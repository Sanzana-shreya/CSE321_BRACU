#include <stdio.h>
#include <stdlib.h>


int main () {


int x , y;
scanf("%d",&x);
scanf("%d",&y);


for (int i = x; i <= y; i++) {
    int ans = i;
    int result = 0;
    for (int j = 1; j <= ans-1; j++) {
    if ((ans % j) == 0) {
    result = result + j; }
    }
    if (ans == result) {
    printf("%d\n",ans);
    }
    }
   
   
   
    return 0;
   






}

