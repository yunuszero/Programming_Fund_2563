#include<stdio.h>

void sort(int *arr, int n) {
	for (int i = 1; i < n; ++i) {
		int temp = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

int main() {
	int n;
	scanf_s("%d", &n);
	int arr[1010];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	sort(arr, n);

	for (int i = 0; i < n; i++) {
		if (arr[0] == 0) {
			for (int j = 1; j < n; j++) {
				if (arr[j] > 0) {
					int temp = arr[0];
					arr[0] = arr[j];
					arr[j] = temp;
					break;
				}
			}
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}

	return 0;
}
