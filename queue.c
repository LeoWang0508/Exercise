#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4
/*
int Queue[MAX_SIZE];
int first = -1, last = -1;

void Enqueue(int val) {
	if (last >= MAX_SIZE-1) {
		printf("full\n");
		return;
	}
	last++;
	Queue[last] = val;
}

int Dequeue() {
	if(last <= -1) {
		printf("empty\n");
		return;
	}
	int i, ans = Queue[first+1];
	for(i = 0; i < last-1; i++) {
		Queue[i] = Queue[i+1];
	}
	last--;
	return ans;
}

int main() {
	Enqueue(1);
	printf("%d\n", Queue[0]);
	int a = Dequeue();
	printf("%d\n", a);
	

	return 0;
}*/

/*
void Enqueue(int q[], int val, int *last) {
	if (*last >= MAX_SIZE-1) {
		printf("full\n");
		return;
	}
	(*last)++;
	q[*last] = val;
}
int Dequeue(int q[], int first, int *last) {
	if (*last <= -1) {
		printf("empty\n");
		return;
	}
	int i, ans = q[first+1];
	for(i = 0; i < *last-1; i++) {
		q[i] = q[i+1];
	}
	(*last)--;
	return ans;
}

int main() {
	int Queue[MAX_SIZE], first = -1, last = -1;
	Enqueue(Queue, 1, &last);
	
	printf("%d\n", Queue[0]);
	int a = Dequeue(Queue, first, &last);
	printf("%d\n", a);
	return 0;
}
*/
typedef struct Node {
	int val;
	struct Node *next;
}Node;

Node *Enqueue(Node **head, Node **tail, int val) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->val = val;
	newnode->next = NULL;
	if (*head == NULL && *tail == NULL) {
		*head = newnode;
		*tail = newnode;
		
	}
	else {
		(*tail)->next = newnode;
		(*tail) = newnode;
	}
	return *head;
}

int Dequeue(Node **head) {
	if (*head==NULL) {
		printf("empty\n");
		return;
	}
	int ans = (*head)->val;
	Node *temp = *head;
	*head = (*head)->next;
	free(temp);
	return ans;
}
int main() {
	Node *head = NULL, *tail = NULL;
	head = Enqueue(&head, &tail, 1);
	Enqueue(&head, &tail, 2);
	Enqueue(&head, &tail, 3);
	printf("%d\n", head->val);
	printf("%d\n", tail->val);
	int n = Dequeue(&head);
	printf("%d\n", n);
	printf("%d\n", head->val);
	return 0;
}


