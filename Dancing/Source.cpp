#include<iostream>
using namespace std;

struct member {
	char name[20];
	int height;
};

bool check[10][10];

void sort(struct member*, int);

int selected(struct member*, struct member*, int);

int main() {
	int n;
	struct member M[10], F[10];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> M[i].name >> M[i].height;
	}
	sort(M, n);
	for (int i = 0; i < n; i++) {
		cin >> F[i].name >> F[i].height;
	}
	sort(F, n);
	cout << selected(M, F, n) << endl;
	// Printed output.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (check[i][j]) {
				printf("%s %s\n", M[i].name, F[j].name);
			}
		}
	}
	return 0;
}

void sort(struct member *x, int n) {
	struct member temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x[j].height < x[j+1].height) {
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
			}
		}
	}
}

int selected(struct member *m, struct member *f, int n) {
	bool used[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int chk = -1;
		for (int j = 0; j < n; j++) {
			if (m[i].height >= f[j].height && abs(m[i].height - f[j].height) <= 5 && used[j] == 0) {
				chk = j;
			}
			if (chk != -1) {
				check[i][chk] = true;
				used[chk] = true;
				cnt++;
				break;
			}
		}
	}
	return cnt;
}