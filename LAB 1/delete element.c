#include <stdio.h>

void deleteElement(int arr[], int *n, int position) {

    if (position < 0 || position >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

void displayArray(int arr[], int n) {
    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to delete (index): ");
    scanf("%d", &position);

    deleteElement(arr, &n, position);

    displayArray(arr, n);

    return 0;
}
