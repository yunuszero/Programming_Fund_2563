#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int commonCharCount(char* s1, char* s2) {
    int mem[15] = { 0 };
    int cnt = 0;
    for (int i = 0; i < strlen(s1); i++) {
        for (int j = 0; j < strlen(s2); j++) {
            if (s1[i] == s2[j] && mem[j] == 0) {
                cnt++;
                mem[j]++;
                break;
            }
        }
    }
    return cnt;
}

int main() {
    char n[15], m[15];
    scanf("%[a-z] %[a-z]", n, m);
    printf("%d", commonCharCount(n, m));

    return 0;
}