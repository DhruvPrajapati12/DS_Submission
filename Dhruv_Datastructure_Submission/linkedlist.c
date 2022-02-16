//Implementation of singly linkedlist.

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head;

struct copynode
{
	int field;
	struct copynode *ptr;
}*begin;

int insertFirst(int x)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	if(newNode==NULL)
	{
		printf("Availability stack underflow\n");
		return 0;
	}

	newNode -> data = x;
	newNode -> next = head;
	head=newNode;

	printf("%d inserted successfully\n",x);

	//printf("%p\n", newNode -> next);
	//printf("value = %d\n", newNode -> data); 
	//printf("address = %p\n", newNode -> next);
	
}

int insertEnd(int x)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	if(newNode==NULL)
	{
		printf("Availability stack underflow\n");
		return 0;
	}

	if(head == NULL)
	{
		newNode -> data = x;
		newNode -> next = NULL;
		head = newNode;
		printf("%d inserted successfully\n",x);
		return 0;
	}

	struct node *temp;
	temp = head;
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = newNode;
	newNode -> data = x;
	newNode -> next = NULL;
	printf("%d inserted successfully\n",x);
}

int insertInSorted(int x)
{
	struct node *newNode;
	struct node *save;
	newNode = (struct node*)malloc(sizeof(struct node));

	if(newNode==NULL)
	{
		printf("Availability stack underflow\n");
		return 0;
	}

	newNode -> data = x;

	if(head == NULL)
	{
		newNode -> next = NULL;
		head = newNode;
		printf("%d inserted successfully\n",x);
		return 0;
	}

	if(x <= head -> data)
	{
		newNode -> next = head;
		head = newNode;
		printf("%d inserted successfully\n",x);
		return 0;
	}

	save = head;
	
	while(save -> next != NULL && newNode -> data >= save -> next -> data)
	{
		save = save -> next;
	}
	newNode -> next = save -> next;
	save -> next = newNode;
	printf("%d inserted successfully\n",x);

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
		printf("%d -> ", temp -> data);
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

int delete(int num)
{
	if(head==NULL)
	{
		printf("Linkedlist is empty.\n");
		return 0;
	}
	struct node *save;
	struct node *prec;
	save = head;
	while(save -> data != num && save -> next != NULL)
	{
		prec = save;
		save = save -> next;
	}
	
	if(save -> data != num)
	{
		printf("Element not found\n");
		return 0;
	}
	if(num == head -> data)
	{
		head = head -> next;
		printf("%d deleted successfully\n", num);
	}
	else
	{
		prec -> next = save -> next;
		printf("%d deleted successfully\n", num);
		free(save);
	}
	
}

int copy()
{
	struct copynode *newNode;
	//struct copynode *new;
	struct copynode *prec;
	struct node *save;
	newNode = (struct copynode*)malloc(sizeof(struct copynode));
	
	if(head==NULL)
	{
		printf("Linkedlist is empty.\n");
		return 0;
	}

	if(newNode==NULL)
	{
		printf("Availability stack underflow\n");
		return 0;
	}

	if(head -> next == NULL)
	{
		newNode -> field = head -> data;
		newNode -> ptr = NULL;
		begin = newNode;
		printf("Copied successfully(Only head node in linkedlist)\n");
		printf("copied linkedlist is: ");
		while(begin != NULL)
		{
			printf("%d -> ", begin -> field);
			begin = begin -> ptr;
		}
		printf("\n");
		return 0;
	}

	newNode -> field = head -> data;
	begin = newNode;

	save = head;
	
	while(save -> next != NULL)
	{
		prec = newNode;
		save = save -> next;
		newNode = (struct copynode*)malloc(sizeof(struct copynode));
		newNode -> field = save -> data;
		prec -> ptr = newNode;
	}

	newNode -> ptr = NULL;
	printf("Copied successfully\n");

	printf("copied linkedlist is: ");

	while(begin != NULL)
	{
		printf("%d -> ", begin -> field);
		begin = begin -> ptr;
	}
	printf("\n");
}

int main()
{
	int x, op=0, del;

	/*struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;
	head = (struct node*)malloc(sizeof(struct node)); 
	second = (struct node*)malloc(sizeof(struct node)); 
	third = (struct node*)malloc(sizeof(struct node));
	fourth = (struct node*)malloc(sizeof(struct node)); 
	head -> data = 23;
	head -> next = second;
	
	second -> data = 45;
	second -> next = third;

	third -> data = 67;
	third -> next = fourth;

	fourth -> data = 87;
	fourth -> next = NULL;*/
	
	//head = (struct node*)malloc(sizeof(struct node));
	//head -> data = 50;
	//head -> next = NULL;
	
	while(op<8)
	{
		printf("1. Insert an element at start\n2. Insert an element at end\n3. Insert an element in beetween in sorted list\n4. Print Linkedlist\n5. Count Number of elements.\n6. Delete Element\n7. Copy linkedlist\n8. Exit\n");
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
			insertInSorted(x);
			break;

			case 4:
			print();
			break;

			case 5: 
			printf("Number of elements are %d\n", count());
			break;

			case 6:
			printf("Enter the number do you want to delete: ");
			scanf("%d", &del);
			delete(del);
			break;

			case 7:
			copy();
			break;

			case 8:
			return 0;
		}
		
	}
	
}


