#include<stdio.h>

bool sudoku(int grid[9][9]) {
    for (int c = 1; c <= 9; ++c) {
        for (int i = 0; i < 9; ++i) {
            int l1 = 0, l2 = 0, l3 = 0;
            for (int j = 0; j < 9; ++j) {
                if (grid[i][j] == c) l1++;
                if (grid[j][i] == c) l2++;
                if (grid[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + (j % 3)] == c) l3++;
            }
            if (l1 > 1 || l2 > 1 || l3 > 1) return false;
        }
    }
    return true;
}

int main() {
    int grid[901][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf_s("%d", &grid[i][j]);
        }
    }
    
    if (sudoku(grid)) {
        printf("true");
    }
    else {
        printf("false");
    }

    return 0;
}