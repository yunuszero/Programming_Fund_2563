#include<iostream>
using namespace std;

int main()
{
    int L, N, i, j, temp;
    scanf_s("%d %d", &L, &N);
    string str1, str2;
    cin >> str1;
    for (i = 0; i < N; i++)
    {
        temp = 0;
        cin >> str2;
        for (j = 0; j < L; j++)
        {
            if (str1[j] != str2[j])
                temp++;
        }
        if (temp > 2)
        {
            cout << str1;
            return 0;
        }
        str1 = str2;
    }
    cout << str1;
    return 0;
}