#include<stdio.h>

int maini() {
    int matrix[15][15];
    int n, m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < sizeof(matrix[0])/ sizeof(matrix[0][0]); i++) {
        sum += matrix[0][i];
        for (int j = 1; j < sizeof(matrix) / sizeof(matrix[0]); j++) {
            if (matrix[j - 1][i])
                sum += matrix[j][i];
            else break;
        }
    }
}