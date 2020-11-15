#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* rotateRight(struct ListNode** head, int k) {
	if (!head || k == 0) return *head;

	struct ListNode* current = *head;
	int n = 1;
	while (current->next)
	{
		current = current->next;
		n++;
	}

	k = k % n;
	if (k == 0) return *head;
	k = n - k;

	current->next = *head;
	struct ListNode* newHead = *head;

	for (int i = 0; i < k - 1; i++)
		newHead = newHead->next;

	*head = newHead->next;
	newHead->next = NULL;
	return *head;
}

void addtoBack(ListNode** head, int data)
{	/*allocate node*/
		struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newnode->val =	data;
		newnode->next = NULL;

		struct ListNode* current = *head;
		if (*head == NULL) {
			*head = newnode;
			return;
		}
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newnode;
}

void printedList(struct ListNode* node) {
	printf("[%d", node->val);
	while (node->next != NULL) {
		node = node->next;
		printf(", %d", node->val);
	}
	printf("]\n");
}

int main() {
	struct ListNode* node = NULL;
	int n, data[100010];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}
	int k;
	scanf_s("%d", &k);
	for (int i = 0; i < n; i++)
		addtoBack(&node, data[i]);
	printf("list before rotated : \t");
	printedList(node);
	rotateRight(&node, k);
	printf("list after rotated : \t");
	printedList(node);

	return 0;
}