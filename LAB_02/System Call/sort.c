#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int i, j, temp;
    int n = argc - 1;
    int arr[n];


    for (i = 1; i <= n; i++) {
        arr[i-1] = atoi(argv[i]);
    }


    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


    printf("Sorted array [descending]: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}



