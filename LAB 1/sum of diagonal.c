#include <stdio.h>
#define SIZE 10

void findLeftDiagonalSum(int matrix[][SIZE], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of the left diagonal: %d\n", sum);
}

int main() {
    int n, matrix[SIZE][SIZE];

    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    if (n > SIZE || n <= 0) {
        printf("Invalid matrix size! Enter a value between 1 and %d.\n", SIZE);
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    findLeftDiagonalSum(matrix, n);

    return 0;
}
