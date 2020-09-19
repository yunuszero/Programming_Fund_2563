#include<iostream>
#include<string.h>
using namespace std;

int main() {
	string A, B;
	char op;
	cin >> A >> op >> B;
	short len1 = A.length(), len2 = B.length();
	if (op == '*') {
		cout << "1";
		for (short i = 0; i < len1 + len2 - 2; i++) {
			cout << "0";
		}
	}
	else if (op == '+') {
		if (len1 > len2) {
			for (short i = 0; i < len1; i++) {
				cout << A[i];
				if (i == len1 - len2 - 1) {
					for (short j = 0; j < len2; j++) {
						cout << B[j];
					}
					break;
				}
			}
		}
		else if (len1 < len2) {
			for (short i = 0; i < len2; i++) {
				cout << B[i];
				if (i == len2 - len1 - 1) {
					for (short j = 0; j < len1; j++) {
						cout << A[j];
					}
					break;
				}
			}
		}
		else {
			cout << "2";
			for (short i = 1; i < len1; i++) {
				cout << A[i];
			}
		}
	}

	return 0;
}
