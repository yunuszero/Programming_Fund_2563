//NOT DONE YET!!!
#include<iostream>
#include<string>
using namespace std;

string multipleStr(string x, string y) {
    int n = x.size();
    int m = y.size();
    string ans(n + m, '0');
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int p = (x[i] - '0') * (y[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = p % 10 + '0';
            ans[i + j] += p / 10;
        }
    }
    for (int i = 0; i < m + n; i++) {
        if (ans[i] != '0')return ans.substr(i);
    }
    return "0";
}

int main() {
	string s;
	cin >> s;
	string result = multipleStr(s,s);
    cout << result;
	return 0;
}