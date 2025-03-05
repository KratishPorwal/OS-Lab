#include <stdio.h>

void countDuplicates(int arr[], int n) {
    int count = 0;
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        int duplicateCount = 0;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1;
                duplicateCount++;
            }
        }

        if (duplicateCount > 0) {
            count += duplicateCount;
        }
    }

    printf("Total number of duplicate elements: %d\n", count);
}

int main() {
    int n, arr[100];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countDuplicates(arr, n);

    return 0;
}
