#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	int max = 0,n;
	char s[30][30];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		if (max < strlen(s[i])) {
			max = strlen(s[i]);
		}
	}
	for (int i = 0; i < strlen(s[i]); i++) {
		if (max == strlen(s[i])) {
			printf("%s\n", s[i]);
		}
	}

	return 0;
}