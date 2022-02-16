#include <stdio.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node *left;
	struct node *right;
};

void inOrder(struct node *node)
{
	if(node==NULL)
		return;
	if(node -> left != NULL)
		inOrder(node -> left);
	printf("%c ", node -> data);
	if(node -> right != NULL)
		inOrder(node -> right);
}

void preOrder(struct node *node)
{
	if(node==NULL)
		return;
	printf("%c ", node -> data);
	if(node -> left != NULL)
		preOrder(node -> left);
	if(node -> right != NULL)
		preOrder(node -> right);
}

void postOrder(struct node *node)
{
	if(node==NULL)
		return;
	if(node -> left != NULL)
		postOrder(node -> left);
	if(node -> right != NULL)
		postOrder(node -> right);
	printf("%c ", node -> data);
}

void main()
{
	struct node *a,*b,*c,*d,*e,*f,*g;
	
	//t = (struct node*)malloc(sizeof(struct node));
	a = (struct node*)malloc(sizeof(struct node));
	b = (struct node*)malloc(sizeof(struct node));
	c = (struct node*)malloc(sizeof(struct node));
	d = (struct node*)malloc(sizeof(struct node));
	e = (struct node*)malloc(sizeof(struct node));
	f = (struct node*)malloc(sizeof(struct node));
	g = (struct node*)malloc(sizeof(struct node));
	
	//t -> right = a;

	a -> data = 'a';
	a -> left = b;
	a -> right = d;

	b -> data = 'b';
	b -> left = c;
	b -> right = NULL;

	c -> data = 'c';
	c -> left = NULL;
	c -> right = NULL;

	d -> data = 'd';
	d -> left = e;
	d -> right = g;

	e -> data = 'e';
	e -> left = NULL;
	e -> right = f;

	f -> data = 'f';
	f -> left = NULL;
	f -> right = NULL;

	g -> data = 'g';
	g -> left = NULL;
	g -> right = NULL;
	printf("Inorder tree: ");
	inOrder(a);
	printf("\nPreorder tree: ");
	preOrder(a);
	printf("\nPostorder tree: ");
	postOrder(a);
	printf("\n");
}
