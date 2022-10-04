#include <stdio.h>
#include <malloc.h>

#define QSIZE 20

typedef struct node {
	int info;
	struct node *llink;
	struct node *rlink;
} node;

node* queue[QSIZE];
int rear = -1;
int front = -1;

node* create_node(int info) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->info = info;
	new_node->llink = NULL;
	new_node->rlink = NULL;
	return new_node;
}

int is_empty() {
	if (front == rear) {
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue(node* new_node) {
	rear++;
	if (rear == (QSIZE)) {
		rear = 0;
	}
	queue[rear] = new_node;
}

node* dequeue() {
	front++;
	if (front == QSIZE) {
		front = 0;
	}
	return queue[front];
}

void push(node** root, int info) {

	node* new_node = create_node(info);
	node* tmp = *root;

	// ≈сли дерево пустое - нова€ нода становитс€ рутом
	if (*root == NULL) {
		*root = new_node;
	}

	// ≈сли дерево не пустое, а поступивша€ info < чем в текущем tmp
	else if (info < tmp->info) {

		// ѕровер€ем, дошли ли мы до !левого! кра€ и пытаемс€ вставить новый элемент
		if (tmp->llink == NULL) {
			tmp->llink = new_node;
		}

		// ≈сли не дошли до кра€, то углубл€емс€
		else {
			push(&(tmp->llink), info);
		}
	}

	// ≈сли дерево не пустое, а поступивша€ info > чем в текущем tmp
	else if (info > tmp->info) {

		if (tmp->rlink == NULL) {
			tmp->rlink = new_node;
		}

		else {
			push(&(tmp->rlink), info);
		}
	}


}

void print_pre_order(node* root) {

	if (root == NULL) {
		printf("\nTree is empty!\n");
		return;
	}

	else {

		printf("%d ", root->info);

		if (root->llink != NULL) {
			print_pre_order(root->llink);
		}

		if (root->rlink != NULL) {
			print_pre_order(root->rlink);
		}
	}
}

void print_post_order(node* root) {

	if (root == NULL) {
		printf("\nTree is empty!\n");
		return;
	}

	else {

		printf("%d ", root->info);

		if (root->llink != NULL) {
			print_pre_order(root->llink);
		}

		if (root->rlink != NULL) {
			print_pre_order(root->rlink);
		}
	}
}

void print_in_width(node* root) {

	node* tmp = root;

	enqueue(root);

	while (is_empty() != 1) {

		tmp = dequeue();
		printf("%d ", tmp->info);

		//≈сли есть левый наследник, то помещаем его в очередь дл€ дальнейшей обработки
		if (tmp -> llink != NULL) {
			enqueue(tmp->llink);
		}
		//≈сли есть правый наследник, то помещаем его в очередь дл€ дальнейшей обработки
		if (tmp->rlink != NULL) {
			enqueue(tmp->rlink);
		}
	}
}








int main() {
	node* root = NULL;

	push(&root, 23);
	push(&root, 614);
	push(&root, 21);
	push(&root, 3);
	push(&root, 445);
	push(&root, 28);


	printf("\nPrint in depth pre order\n");
	print_pre_order(root);
	printf("\n");

	printf("\nPrint in depth post order\n");
	print_post_order(root);
	printf("\n");

	printf("\nPrint in width\n");
	print_in_width(root);
	printf("\n");



}