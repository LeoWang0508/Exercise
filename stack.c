#include <stdio.h>
#include<stdlib.h>

/*
typedef struct Stack {
	int a[4];
	int top;
}Stack;

void push(Stack *s, int val) {
	if (s->top >= 3) {
		printf("full\n");
		return;
	}
	s->top++;
	s->a[s->top] = val;
}

int pop(Stack *s) {
	if (s->top <= -1) {
		printf("empty");
		return;
	}
	s->top--;
	return s->a[s->top+1];
}
*/
/*
int main() {
	int a = 1, b = 3;
	Stack s;
	s.top = -1;
	push(&s,1);
	int c = pop(&s);
	printf("%d\n", s.a[0]);
	printf("%d\n", c);
	return 0;
}*/


/*
#define max_size 4

void push(int stack[], int val, int *top) {
	if (*top > max_size-1) {
		printf("full\n");
		return;
	}
	(*top)++;
	stack[*top] = val;
}
int pop(int stack[], int *top) {
	if (*top <= -1) {
		printf("empty\n");
		return;
	}
	int data = stack[*top];
	(*top)-;
	return data;
}

int main() {
	int stack[max_size], top = -1;
	push(stack, 5, &top);
	int a = pop(stack, &top);
	printf("%d\n", a);
	
	return 0;
}
*/

typedef struct Node {
	int val;
	struct Node *next;
}Node;

Node *push(Node **node, int val) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->val = val;
	newnode->next = *node;
	*node = newnode;
	return *node;
}

int pop(Node **node) {
	if(node == NULL) {
		printf("empty");
	}
	int ans = (*node)->val;
	Node *temp = *node;
	*node = (*node)->next;
	free(temp);
	return ans;
}

void Print_stack(Node *node) {
	while(node!=NULL) {
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
	return;
}

int main() {
	Node *root = NULL, *top = NULL;
	push(&root,5);
	root = push(&root,6);
	root = push(&root,7);
	root = push(&root,8);
	Print_stack(root);
	printf("%d\n",root->val);
	int n;
	n = pop(&root);
	printf("%d\n",n);
	
	return 0; 
} 



