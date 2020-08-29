#include<stdio.h>

int* alternatingSums(int* a,int n) {
	int b[] = { 0,0 };
	for (int i = 0; i < n; i++) {
		b[i % 2] += a[i];
	}
	return b;
}

int main() {
	int n;
	int arr[1000];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	int *result = alternatingSums(arr, n);
	printf("%d %d", result[0], result[1]);
	
	return 0;
}