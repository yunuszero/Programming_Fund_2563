#include<stdio.h>

void sortByHeight(int* inputArray,int n) {
	for (int i = 0; i < n-1; i++) {
		if (inputArray[i] == -1) {
			continue;
		}
		for (int j = i; j < n; j++) {
			if (inputArray[j] == -1) {
				continue;
			}
			if (inputArray[i] > inputArray[j]) {
				int temp = inputArray[i];
				inputArray[i] = inputArray[j];
				inputArray[j] = temp;
			}
		}
	}
}

int main() {
	int n;
	int array[1000];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]); 
	}
	sortByHeight(array,n);
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}