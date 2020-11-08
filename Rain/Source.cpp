#include <stdio.h>

int trap(int* height, int heightSize) {
    int result = 0;
    int start = 0;
    int end = heightSize - 1;
    while (start < end) {
        if (height[start] <= height[end]) {
            int current = height[start];
            while (height[++start] < current) {
                result += current - height[start];
            }
        }
        else {
            int current = height[end];
            while (height[--end] < current) {
                result += current - height[end];
            }
        }
    }
    return result;
}

int main() {
    int n, height[30001];
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &height[i]);
    }
    printf_s("%d", trap(height, n));

    return 0;
}