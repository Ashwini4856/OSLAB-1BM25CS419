#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = arr[0];
    int secondSmallest = arr[0];


    for(i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }


    for(i = 0; i < n; i++) {
        if(arr[i] > smallest && (secondSmallest == smallest || arr[i] < secondSmallest)) {
            secondSmallest = arr[i];
        }
    }

    if(secondSmallest == smallest) {
        printf("No second smallest element.\n");
    } else {
        printf("Second smallest element = %d\n", secondSmallest);
    }

    return 0;
}
