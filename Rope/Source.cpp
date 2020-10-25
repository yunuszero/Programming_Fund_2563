#include<iostream>
using namespace std;
int dp[1000010];
int cost[10010];

int bestCost(int k) {
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        int hicost = -1e9;
        for (int j = 0; j < i; j++) {
            if (hicost < cost[j] + dp[i - j - 1])
                hicost = cost[j] + dp[i - j - 1];
        }
        dp[i] = hicost;
    }

    return dp[k];
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> cost[i];
    }
    int want;
    cin >> want;
    cout << bestCost(want);

    return 0;
}