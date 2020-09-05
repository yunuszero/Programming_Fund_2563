#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int max = 0,n;
	char s[30][30];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		int len = 0,j=0;
		while (s[i][j] != '\0') {
			len++;
			j++;
		}
		if (max < len) {
			max = len;
		}
	}
	for (int i = 0; i < n; i++) {
		int len = 0, j = 0;
		while (s[i][j] != '\0') {
			len++;
			j++;
		}
		if (max == len) {
			printf("%s\n", s[i]);
		}
	}

	return 0;
}