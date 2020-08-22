#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrix[20][20];
    int n, m;
    scanf_s("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += matrix[0][i];
        for (int j = 1; j < n; j++) {
            if (matrix[j - 1][i])
                sum += matrix[j][i];
            else break;
        }
    }
    printf("%d", sum);

    return 0;
}