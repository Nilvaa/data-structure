#include <stdio.h>

int main() {
    int arr[20], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    printf("Array elements in reverse order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
#include <stdio.h>

// Function to input array elements
void inputArray(int arr[], int n) {
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to print array elements
void printArray(int arr[], int n) {
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

// Function to print array elements in reverse order
void printArrayReverse(int arr[], int n) {
    printf("Array elements in reverse order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int arr[20], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    inputArray(arr, n);
    printArray(arr, n);
    printArrayReverse(arr, n);

    return 0;
}

