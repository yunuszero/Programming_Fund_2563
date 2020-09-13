#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{

	char dice[1001];
	int i, j;
	int num;
	scanf("%d", &num);
	while (num--)
	{
		int top = 1, front = 2, left = 3, back = 5, right = 4, bott = 6;
		scanf("%s", dice);
		for (j = 0; dice[j] != 0; j++)
		{
			int temp;
			if (dice[j] == 'F')
			{
				temp = top;
				top = back;
				back = bott;
				bott = front;
				front = temp;
			}
			else if (dice[j] == 'B')
			{
				temp = top;
				top = front;
				front = bott;
				bott = back;
				back = temp;
			}
			else if (dice[j] == 'L')
			{
				temp = top;
				top = right;
				right = bott;
				bott = left;
				left = temp;
			}
			else if (dice[j] == 'R')
			{
				temp = top;
				top = left;
				left = bott;
				bott = right;
				right = temp;
			}
			else if (dice[j] == 'C')
			{
				temp = front;
				front = right;
				right = back;
				back = left;
				left = temp;
			}
			else if (dice[j] == 'D')
			{
				temp = front;
				front = left;
				left = back;
				back = right;
				right = temp;
			}
		}

		printf("%d ", front);
	}

	return 0;
}