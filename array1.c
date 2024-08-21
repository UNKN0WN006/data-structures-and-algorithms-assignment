#include <stdio.h>
int main() {
    int arr[10];
    int newArr[8];  
    int i, j = 0;

    printf("Enter 10 elements of the array:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;  
        }
        newArr[j++] = arr[i];
    }

    printf("The 5th element of the resulting array is: %d\n", newArr[4]);
    return 0;
}
