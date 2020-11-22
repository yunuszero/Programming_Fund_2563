#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int i, j, bars, area;
    bool cal;
    int max = 0;

    for (i = 0; i < heightsSize; i++) {
        bars = 1;
        cal = false;

        j = i - 1;
        while (j >= 0) {
            if (heights[j] == heights[i]) {
                cal = true;
                break;
            }
            else if (heights[j] > heights[i]) {
                bars++;
                j--;
            }
            else {
                break;
            }
        }

        if (cal == true)
            continue;

        j = i + 1;
        while (j < heightsSize) {
            if (heights[j++] >= heights[i])
                bars++;
            else
                break;
        }

        area = heights[i] * bars;

        if (area > max)
            max = area;
    }

    return max;
}

int main() {
    int n, items[10010];
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &items[i]);
    }
    int ans = largestRectangleArea(items, n);
    printf("%d", ans);

    return 0;
}