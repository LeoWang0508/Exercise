#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *left, *right;
}Node;

Node *CreateNode(int value) {
	Node *newNode = (Node *)malloc(sizeof(Node *));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void preorder(Node *root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
	return;
}

void inorder(Node *root) {
	if (root == NULL) {
		return;
	}
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
	return;
}

void postorder(Node *root) {
	if (root == NULL) {
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
	return;
}

void (*function_order[])(Node *) = {preorder, inorder, postorder};

typedef struct Tree_Queue {
	Node *items[5];
	int start;
	int final;
}Tree_Queue;

void Enqueue(Tree_Queue *q, Node *item) {
	
	if (q->start == (q->final + 1) % 5) {
		printf("Queue is full");
		exit (EXIT_FAILURE);
	}
	q->final++;
	if(q->final == 5) {
		q->final = 0;
	}
	q->items[q->final] = item;
	return;
}

Node *Dequeue(Tree_Queue *q) {
	if (q->start == q->final) {
		printf("Queue is empty");
		exit (EXIT_FAILURE);
	}
	q->start++;
	if (q->start == 5) {
		q->start = 0;
	}
	return q->items[q->start];
}

int queue_is_empty(Tree_Queue *q) {
	return q->start == q->final;
}

typedef struct Tree_Stack {
	Node *stack[16];
	int top;
}Tree_Stack;

void Stack_push(Tree_Stack *s, Node *item) {
	if (s->top == 15) {
		return;
	}
	s->top++;
	s->stack[s->top] = item;
	return;
}

Node *Stack_pop(Tree_Stack *s) {
	if (s->top == -1) {
		return;
	}
	s->top--;
	return s->stack[s->top+1];
}

int stack_is_empty(Tree_Stack *s) {
	return s->top == -1;
}
void BFS(Node *root) {
	Tree_Queue q;
	q.start = -1;
	q.final = -1;
	Enqueue(&q, root);
	
	while(queue_is_empty(&q) == 0) {
		Node *current = Dequeue(&q);
		printf("%d ", current->data);
		if (current->left != NULL) {
			Enqueue(&q,current->left);
		}
		if (current->right != NULL) {
			Enqueue(&q,current->right);
		}
	}
	return;
}

void DFS(Node *root) {
	Tree_Stack s;
	s.top = -1;
	Stack_push(&s, root);

	while (stack_is_empty(&s) == 0) {
		Node *current = Stack_pop(&s);
		printf("%d ", current->data);
		if (current->right != NULL) {
			Stack_push(&s, current->right);
		}	
		if (current->left != NULL) {
			Stack_push(&s, current->left);
		}
	}
	return;
}

int main() {
	Node *root1 = CreateNode(1);
	Node *root2 = CreateNode(2);
	Node *root3 = CreateNode(3);
	Node *root4 = CreateNode(4);
	Node *root5 = CreateNode(5);
	Node *root6 = CreateNode(6);
	Node *root7 = CreateNode(7);
	
	root1->left = root2;
	root1->right = root3;
	
	root2->left = root4;
	root2->right = root5;
	
	root3->left = root6;
	root3->right = root7;
	
	function_order[0](root1);
	printf("\n");
	function_order[1](root1);
	printf("\n");
	function_order[2](root1);
	printf("\n");
	BFS(root1);
	printf("\n");
	DFS(root1);
	printf("\n");
	return 0; 
} 
