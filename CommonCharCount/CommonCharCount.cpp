#include <iostream>
int commonCharCount(std::string s1, std::string s2) {
    int mem[15] = { 0 };
    int cnt = 0;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j] && mem[j] == 0) {
                cnt++;
                mem[j]++;
                break;
            }
        }
    }
    return cnt;
}

int main() {
    std::string n, m;
    std::cin >> n >>m;
    printf("%d", commonCharCount(n, m));

    return 0;
}