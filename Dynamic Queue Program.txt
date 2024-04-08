#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

struct Node
{
	int ele;
	struct Node *next;
};

struct Node *FRONT, *REAR;

void enqueue_op()
{
	struct Node *nn;
	nn = (struct Node *) malloc(sizeof(struct Node));
	printf("Enter element to ENQUEUE : ");
	scanf("%d", &nn->ele);

	if(REAR==NULL)
	{
		nn->next = NULL;
		FRONT = nn;
		REAR = nn;
		printf("Queue Created..\n");
	}
	else
	{
		nn->next = NULL;
		REAR->next = nn;
		REAR = nn;
		printf("Element ENQUEUEed from REAR end.\n");
	} //end of outer else

} //end of enqueue_op()

void dequeue_op()
{
	struct Node *temp;
	if(REAR == NULL)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		if(FRONT == REAR)
		{
			printf("FRONT element %d is DEQUEUEed\n", FRONT->ele);
			temp = FRONT;
			FRONT = NULL;
			REAR = NULL;
			free(temp);
		}
		else
		{
			printf("FRONT element %d is DEQUEUEed\n", FRONT->ele);
			temp = FRONT;
				FRONT = FRONT->next;
			free(temp);
		}
	} //end of else block
} //end of dequeue_op()

void display_op()
{
	struct Node *temp;
	if(REAR == NULL)
	{
		printf("Queue is Empty. Nothing to Display.\n");
	}
	else
	{
		printf("Queue Contains\n");
		temp = FRONT;
		while(temp!=NULL)
		{
			printf("%d\t", temp->ele);
			temp = temp->next;
		}
		printf("\n");
	} //end of else block
} //end of display_op()


void main()
{
	int ch;
	clrscr();

	FRONT = NULL;
	REAR = NULL;

	do
	{
		getch();
		clrscr();
		printf("Select operation\n");
		printf("1 - ENQUEUE operation\n");
		printf("2 - DEQUEUE operation\n");
		printf("3 - DISPLAY operation\n");
		printf("4 - EXIT\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: enqueue_op();
				break;
			case 2: dequeue_op();
				break;
			case 3: display_op();
				break;
			case 4: exit(0);
		} //end of switch-case
	}while(1);

	getch();
}


