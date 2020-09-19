#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    string Testcase[21];

    for (int i = 0; i < n; i++) {
        cin >> Testcase[i];
    }

    for (int i = 0; i < n; i++) {
        int check = 0, cnt = 0;
        for (int j = 0; j < Testcase[i].length(); j++) {
            if (Testcase[i][j] == 'X') {
                check = 1;
                break;
            }
            else if (Testcase[i][j] == 'T') {
                check = 2;
                cnt++;
            }
            else if (Testcase[i][j] == '-' && cnt == 0) {
                check = 3;
            }
        }
        switch (check) {
        case 1: printf("Case #%d: No - Runtime error\n", i + 1); break;
        case 2: printf("Case #%d: No - Time limit exceeded\n", i + 1); break;
        case 3: printf("Case #%d: No - Wrong answer\n", i + 1); break;
        default: printf("Case #%d: Yes\n", i + 1); break;

        }
    }

    return 0;
}