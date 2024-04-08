#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

struct Node
{
	int ele;
	struct Node *next;
};

struct Node *TOP;

void push_op()
{
	struct Node *nn;
	nn = (struct Node *) malloc(sizeof(struct Node));
	printf("Enter element to PUSH : ");
	scanf("%d", &nn->ele);

	if(TOP == NULL)
	{
		nn->next = NULL;
		TOP = nn;
		printf("Stack Created...\n");
	}
	else
	{
		nn->next = TOP;
		TOP = nn;
		printf("Element PUSHed into the Stack\n");
	} //end of outer else block
} //end of push_op()

void pop_op()
{
	struct Node *temp;
	if(TOP == NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("TOP element %d is POPed out \n", TOP->ele);
		temp = TOP;
		TOP = TOP->next;
		free(temp);
	} //end of outer else block
} //end of pop_op()

void display_op()
{
	struct Node *temp;
	if(TOP == NULL)
	{
		printf("Stack is Empty. Nothing to Display.\n");
	}
	else
	{
		printf("Stack contains\n");
		temp = TOP;
		while(temp!=NULL)
		{
			printf("%d\n", temp->ele);
			temp = temp->next;
		}
	} // end of outer else block
} //end of display_op()

void main()
{
	int ch;
	clrscr();

	TOP = NULL;

	do
	{
		clrscr();
		printf("\nSelect operation\n");
		printf("1 - PUSH operation\n");
		printf("2 - POP operation\n");
		printf("3 - DISPLAY operation\n");
		printf("4 - EXIT\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: push_op();
				break;
			case 2: pop_op();
				break;
			case 3: display_op();
				break;
			case 4: exit(0);
		} //end of switch-case


	}while(1);

	getch();


}




