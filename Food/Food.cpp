#include <stdio.h>
int n, m;
bool notch[8], choose[8];
int pick[8];

void food(int p) {
    if (p < n) {
        for (int i = 0; i < n; i++) {
            if (p == 0 && notch[i])
                continue;
            if (choose[i])
                continue;
            choose[i] = true;
            pick[p] = i + 1;
            food(p + 1);
            choose[i] = false;
        }
    }
    else {
        printf("%d", pick[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", pick[i]);
        }
        printf("\n");
    }
}

int main() {
    scanf_s("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf_s("%d", &x);
        notch[x - 1] = true;
    }
    food(0);

    return 0;
}