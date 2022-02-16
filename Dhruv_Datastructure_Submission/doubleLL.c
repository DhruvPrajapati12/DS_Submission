//Implementation of doubly linkedlist.

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head, *last;


int insertFirst(int x)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode -> data = x;
	
	if(head == NULL)
	{
		newNode -> prev = NULL;
		newNode -> next = NULL;
		head = last = newNode;
		printf("%d inserted successfully\n",x);
		return 0;
	}

	head -> prev = newNode;
	newNode -> next = head;
	newNode -> prev = NULL;
	head = newNode;
	printf("%d inserted successfully\n",x);
}

int insertEnd(int x)
{
	
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode -> data = x;
	
	if(head == NULL)
	{
		newNode -> prev = NULL;
		newNode -> next = NULL;
		head = last = newNode;
		printf("%d inserted successfully\n",x);
		return 0;
	}

	last -> next = newNode;
	newNode -> next = NULL;
	newNode -> prev = last;
	last = newNode;
	printf("%d inserted successfully\n",x);
}

int search(int x)
{
	if(head == NULL)
	{
		printf("Linked list is empty\n");
	}
	struct node *temp;
	int count = 1;
	temp = head;
	while(temp != NULL)
		{
			if(x == temp -> data)
			{
				return count;
			}
			temp = temp -> next;
			count++;
		}
}

int insertMiddle(int x)
{
	/*
	struct node *newNode;
	struct node *l;
	struct node *r;
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode -> data = x;
	l = head;
	r = last;
	while(l -> next != r -> prev)
	{
		if(l -> next == r -> prev)
		{
			l -> next = newNode;
			newNode -> next = r;
			r -> prev = newNode;
			newNode -> prev = l;
			printf("%d inserted successfully\n",x);
			break;
		}
		l = l -> next;
		r = r -> prev;
	}
	*/
	
}
	
int print()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Linkedlist is empty.\n");
		return 0;
	}
	printf("Elements of linkedlist is: ");
	temp = head;
	while(temp != NULL)
	{
		printf("%d <=> ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

int count()
{
	
	struct node *temp;
	int count=0;
	if(head==NULL)
	{
		printf("Linkedlist is empty.\n");
		return 0;
	}
	temp = head;
	while(temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	return count;
}

int delete(int x)
{
	struct node *temp;
	if(head == NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	if(x == head -> data)
	{
		if(head == last)
		{
			head = last = NULL;
			printf("%d deleted successfully\n", x);
			return 0;
		}

		head = head -> next;
		head -> prev = NULL;
		
		printf("%d deleted successfully\n", x);
	}
	else if(x == last -> data)
	{
		last = last -> prev;
		last -> next = NULL;
		printf("%d deleted successfully\n", x);
	}
	else
	{
		temp = head;
		while(temp  != NULL)
		{
			temp = temp -> next;
			if(x == temp -> data)
			{
				break;
			}
		}	
		if(x != temp -> data)
		{
			printf("Element not found\n");
			return 0;
		}
		temp -> prev -> next = temp -> next;
		temp -> next -> prev = temp -> prev;
		printf("%d deleted  successfully\n", x);
	}
}

int main()
{
	int x, op=0, del;

	while(op<8)
	{
		printf("1. Insert an element at first\n2. Insert an element at last\n3. Insert an element at middle\n4. Print Linkedlist\n5. Count Number of elements.\n6. Delete an Element from doubly linked list\n7. Position\n8. Exit\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			printf("Enter an element: ");
			scanf("%d", &x);
			insertFirst(x);
			break;

			case 2:
			printf("Enter an element: ");
			scanf("%d", &x);
			insertEnd(x);
			break;

			case 3:
			printf("Enter an element: ");
			scanf("%d", &x);
			//insertMiddle(x);
			break;

			case 4:
			print();
			break;

			case 5: 
			printf("Number of elements are %d\n", count(head));
			break;

			case 6:
			printf("Enter the number do you want to delete: ");
			scanf("%d", &del);
			delete(del);
			break;

			case 7:
			printf("Enter the number do you want to search: ");
			scanf("%d", &x);
			printf("%d is present at index number %d\n",x, search(x));
			break;

			case 8:
			return 0;
		}
		
	}
}
