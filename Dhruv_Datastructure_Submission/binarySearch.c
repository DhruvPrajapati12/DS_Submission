//Implementation of Binary search tree, searching, inserting, and deleting node.

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

void preOrder(struct node *node)
{
	if(node==NULL)
		return;
	printf("%d ", node -> data);
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
	printf("%d ", node -> data);
}

void inOrder(struct node *node)
{
	if(node==NULL)
		return;
	if(node -> left != NULL)
		inOrder(node -> left);
	printf("%d ", node -> data);
	if(node -> right != NULL)
		inOrder(node -> right);
}

struct node* createNode(int x)
{
	struct node *node;
	node = (struct node*)malloc(sizeof(struct node));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct node* searchNdInsert(struct node* node, int k)
{
	if (node == NULL)
		return createNode(k);
	if (k < node->data)
		node->left = searchNdInsert(node->left, k);
	else if (k > node->data)
		node->right = searchNdInsert(node->right, k);
	return node;
}

//struct node* deleteNode(struct node* node, int x)
//{
//	if (x < node->data)
//		node->left = deleteNode(node -> left, x);
//	else if (x > node->data)
//		node->right = deleteNode(node -> right,x);
//	return node;
//}

int successor(struct node *root) 
{
    root = root -> right;
	while (root -> left != NULL) 
	{
		root = root -> left;
	}
	return root -> data;
}

int predecessor(struct node *root) 
{
	root = root -> left;
  	while (root -> right != NULL)
	{
		 root = root -> right;
	}
  	return root -> data;
}

struct node* deleteNode(struct node *root, int key)
{
	if (root == NULL) 
		return NULL;
  	if (key > root -> data)
	{
		root -> right = deleteNode(root -> right, key);
	} 
    else if (key < root -> data) 
	{	
		root->left = deleteNode(root -> left, key);
	}
    else 
	{
		if (root -> left == NULL && root -> right == NULL) 
			root = NULL;
		else if (root -> right != NULL) 
		{
		  	root -> data = successor(root);
		  	root -> right = deleteNode(root -> right, root -> data);
		} 
		else 
		{
		  	root -> data = predecessor(root);
		  	root -> left = deleteNode(root -> left, root -> data);
		}
	}
	return root;
}


int main()
{
	struct node* root;

	root = searchNdInsert(root,50);
	searchNdInsert(root, 20);
	searchNdInsert(root, 60);
	searchNdInsert(root, 23);
	searchNdInsert(root, 10);
	searchNdInsert(root, 15);
	searchNdInsert(root, 55);
	searchNdInsert(root, 57);
	searchNdInsert(root, 80);
	searchNdInsert(root, 65);

	searchNdInsert(root, 22);
	searchNdInsert(root, 90);
	searchNdInsert(root, 85);
	searchNdInsert(root, 34);
	searchNdInsert(root, 5);

	printf("Inorder tree: ");
	inOrder(root);
	printf("\nPreorder tree: ");
	preOrder(root);
	printf("\nPostorder tree: ");
	postOrder(root);
	printf("\n");

	deleteNode(root, 50);
	deleteNode(root, 57);
	deleteNode(root, 80);
	printf("After deleting 50, 57, 80 \nPreorder tree: ");
	preOrder(root);
	printf("\n");

	return 0;
}

