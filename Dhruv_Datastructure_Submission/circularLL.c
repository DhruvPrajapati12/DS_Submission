//Implementation of circular linkedlist.

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head, *last;

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

	if(head == NULL)
	{
		newNode -> next = newNode;
		head = last = newNode;
		printf("%d inserted successfully\n",x);
	}
	else
	{
		newNode -> next = head;
		head = newNode;
		last -> next = head;

		printf("%d inserted successfully\n",x);
	}

	
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
	
	newNode -> data = x;

	if(head == NULL)
	{
		newNode -> next = newNode;
		head = last = newNode;
		printf("%d inserted successfully\n",x);
	}
	else
	{
		last -> next = newNode;
		newNode -> next = head;
		last = newNode;
		printf("%d inserted successfully\n",x);
	}
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
		newNode -> next = newNode;
		head = last = newNode;
		printf("%d inserted successfully\n",x);
		return 0;
	}

	if(x <= head -> data)
	{
		newNode -> next = head;
		head = newNode;
		last -> next = head;
		printf("%d inserted successfully\n",x);
		return 0;
	}

	if(x >= last -> data)
	{
		newNode -> next = head;
		last -> next = newNode;
		last = newNode;
		printf("%d inserted successfully\n",x);
		return 0;
	}

	save = head;
	
	while(save -> next != last -> next && newNode -> data >= save -> next -> data)
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
	while(temp -> next != last -> next)
	{
		printf("%d -> ", temp -> data);
		temp = temp -> next;
	}
	printf("%d -> %d\n", last -> data, last -> next -> data);
	
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
	count++;
	while(temp -> next != last -> next)
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
	while(save -> data != num && save -> next != last -> next)
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
		if(head -> next == head)
		{
			head = last = NULL;
			printf("%d deleted successfully\n", num);
			return 0;
		}
		head = head -> next;
		last -> next = head;
		printf("%d deleted successfully\n", num);
	}
	else
	{
		if(num == last -> data)
		{
			last = prec;
			prec -> next = head;
			printf("%d deleted successfully\n", num);
			return 0;
		}
		prec -> next = save -> next;
		printf("%d deleted successfully\n", num);
		free(save);
	}
	
}	

int main()
{
	int x, op=0, del;	
	
	/*struct node *middle;
	
	head = (struct node*)malloc(sizeof(struct node));
	middle = (struct node*)malloc(sizeof(struct node));
	last = (struct node*)malloc(sizeof(struct node));

	head -> data = 30;
	head -> next = middle;

	middle -> data = 50;
	middle -> next = last;

	last -> data = 70;
	last -> next = head;*/

	while(op<7)
	{
		printf("1. Insert an element at start\n2. Insert an element at end\n3. Insert an element in beetween in sorted list\n4. Print Linkedlist\n5. Count Number of elements.\n6. Delete Element\n7. Exit\n");
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
			return 0;
		}
		
	}
}
