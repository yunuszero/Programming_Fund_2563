#include<iostream>
using namespace std;

bool check(int x, int y) {
	if (x / 100 == y / 100) return true;
	x %= 100, y %= 100;
	if (x / 10 == y / 10) return true;
	x %= 10, y %= 10;
	if (x == y) return true;

	return false;
}

int main() {
	long long id[1000] = { 0 };
	long long n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x, id[x]++;
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (check(i, j)) {
				if (i != j) ans += id[i] * id[j];
				else ans += id[i] * (id[i] - 1);
			}
		}
	}
	printf("%lld", ans / 2);
	return 0;
}