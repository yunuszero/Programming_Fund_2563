//NON MATHEMATICS SOLUTION
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string plusStr(string x, string y) {
    int n = x.size();
    int m = y.size();
    int mx = max(n, m);
    string ans(mx + 1, '0');
    int r, p = 0;
    for (int i = 0; i <= mx; i++) {
        r = ((n - i - 1 >= 0) ? x[n - i - 1] - '0' : 0) + ((m - i - 1 >= 0) ? y[m - i - 1] - '0' : 0) + p;
        p = r / 10;
        ans[mx - i] = r % 10 + '0';
    }
    for (int i = 0; i <= mx; i++) {
        if (ans[i] != '0')return ans.substr(i);
    }
    return "0";
}

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

string selfpowStr(string x) {
    int n = stod(x);
    string ans = x;
    for (int i = 2; i <= n; i++) {
        ans = multipleStr(ans, x);
    }
    return ans;
}

int main() {
    string s, result = "0", temp;
	cin >> s;
    for (int i = 1; i <= stod(s); i++) {
        temp = selfpowStr(to_string(i));
        temp = plusStr(result, temp);
        result = temp;
    }
    cout << result;
    
	return 0;
}