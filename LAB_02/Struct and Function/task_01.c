#include <stdio.h>
#include <stdlib.h>


int paratha(int p, int x);
int vegetable(int v, int y);
int water(int w, int z);


int main() {


int total;
int p,x,v,y,w,z;
float number;


printf("Quantity Of Paratha: ");
scanf("%d",&p);
printf("Unit Price: ");
scanf("%d",&x);
printf("Quantity Of Vegetables: ");
scanf("%d",&v);
printf("Unit Price: ");
scanf("%d",&y);
printf("Quantity Of Mineral Water: ");
scanf("%d",&w);
printf("Unit Price: ");
scanf("%d",&z);


printf("Number of People: ");
scanf("%f",&number);




total = paratha(p,x) + vegetable(v,y) + water(w,z);


float t = (float) total;
float answer = t / number;
printf("Individual people will pay : %0.2f tk\n",answer);




}


int paratha(int p, int x) {
int ans = p * x;
return ans;
}


int vegetable(int v, int y) {
int ans = v * y;
return ans;
}


int water(int w, int z) {
int ans = w * z;
return ans;
}







