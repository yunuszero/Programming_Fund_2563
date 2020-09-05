#include<stdio.h>

int main() {
	int p, dmg[2] = { 0,0 }, count[2] = { 0,0 };
	scanf_s("%d", &p);
	int i = 2 * p;
	while (i >= 0) {
		int n;
		scanf_s("%d", &n);
		count[!(n % 2)] = 0;
		count[n % 2]++;
		if (count[n % 2] >= 3) {
			dmg[n % 2] += 3;
		}
		else {
			dmg[n % 2]++;
		}
		if (dmg[n % 2] >= p) {
			printf("%d\n%d", n % 2, n);
			break;
		}
		i--;
	}

	return 0;
}