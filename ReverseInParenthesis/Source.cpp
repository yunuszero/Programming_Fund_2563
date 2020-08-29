#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void reverseInParentheses(char* s) {
    int matchFound = 1;
    while(matchFound){
        int index, startIdx;
        matchFound = 0;
        for (index = 0; s[index] != '\0'; index++)
        {
            if (s[index] == '(')
            {
                startIdx = index;
                continue;
            }
            if (s[index] == ')')
            {
                int i = index - 1;
                int isOdd = (i - startIdx) % 2;
                char temp = s[i];
                for (; startIdx < i - 1;)
                {
                    s[startIdx++] = temp;
                    temp = s[--i];
                    s[i] = s[startIdx];
                }
                if (isOdd) 
                {
                    s[startIdx] = temp;
                }
                for (i = index + 1; s[i] != '\0'; i++)
                {
                    s[i - 2] = s[i];
                }
                s[i - 2] = '\0';
                matchFound = 1;
                break;
            }
        }

    }
}

int main() {
    char text[51];
    scanf("%s", text);
    reverseInParentheses(text);
    printf("%s", text);

    return 0;
}