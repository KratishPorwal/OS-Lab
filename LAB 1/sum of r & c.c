#include <stdio.h>
#define SIZE 10

void findRowColumnSums(int matrix[][SIZE], int rows, int cols) {
    int rowSum, colSum;

    printf("Sum of each row:\n");
    for (int i = 0; i < rows; i++) {
        rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Row %d: %d\n", i + 1, rowSum);
    }

    printf("\nSum of each column:\n");
    for (int j = 0; j < cols; j++) {
        colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        printf("Column %d: %d\n", j + 1, colSum);
    }
}

int main() {
    int rows, cols, matrix[SIZE][SIZE];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows > SIZE || cols > SIZE || rows <= 0 || cols <= 0) {
        printf("Invalid matrix size! Enter values between 1 and %d.\n", SIZE);
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    findRowColumnSums(matrix, rows, cols);

    return 0;
}
