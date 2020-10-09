#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int mem[1010][1010];
string a, b;
int LCS(int n, int m) {
    if (n == -1 || m == -1) return 0;
    if (mem[n][m] != -1) return mem[n][m];
    int ans = 0;
    if (a[n] == b[m]) {
        ans = LCS(n - 1, m - 1) + 1;
    }
    else {
        ans = max(LCS(n - 1, m), LCS(n, m - 1));
    }
    mem[n][m] = ans;
    return ans;
}

int main() {
    cin >> a >> b;
    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            mem[i][j] = -1;
        }
    }
    cout << LCS(a.size() - 1, b.size() - 1);

    return 0;
}