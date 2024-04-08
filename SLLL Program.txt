#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int ele;
	struct Node *next;
};

struct Node *first;

void insert_node()
{
	struct Node *nn, *temp;
	int ch, sel_ele;

	nn = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter element for New Node : ");
	scanf("%d", &nn->ele);
	nn->next = NULL;

	if(first == NULL)
	{
		first = nn;
		printf("List Created...\n");
	}
	else
	{
		printf("Where you want to Place this New Node\n");
		printf("1 - At First Position\n");
		printf("2 - At Last Position\n");
		printf("3 - At Select Position\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: // inserting NN at first position
				nn->next = first;
				first = nn;
				printf("New Node is Placed at First Position\n");
				break;
			case 2: // inserting NN at last position
				temp = first;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				// At the end "temp" points to last node
				nn->next = NULL;
				temp->next = nn;
				printf("New Node is Placed at Last Position\n");
				break;
			case 3: // inserting NN after selected node
				printf("Enter element of that node, after which you want to place NN : ");
				scanf("%d", &sel_ele);
				temp = first;
				while(temp->ele != sel_ele && temp!=NULL)
				{
					temp = temp->next;
				}

				if(temp==NULL)
				{
					// means we've search upto last ode.
					printf("No such node present. New Node is Dropped.\n");
				}
				else
				{
					// means Select node found.
					// temp points to selected node.
					nn->next = temp->next;
					temp->next = nn;
					printf("New Node is Placed after Selected Node\n");
				}
				break;
		} //end of swith-case
	} // end of outer else block
} //end of insert_node()

void remove_node()
{
	struct Node *temp, *temp2;
	int ch, sel_ele;

	if(first == NULL)
	{
		printf("List Underflow\n");
	}
	else
	{
	    if(first->next == NULL)
	    {
			// There is only one node present.
			temp = first;
			first = NULL;
			free(temp);
			printf("There was only one Node. It is now Removed from List.\n");
	    }
	    else
	    {
		printf("Which Node you want to Remove?\n");
		printf("1 - Remove First Node\n");
		printf("2 - Remove Last Node\n");
		printf("3 - Remove Selected Node\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: // removing first node
				temp = first;
				first = first->next;
				free(temp);
				printf("First Node is Removed from List\n");
				break;
			case 2: // removing last node
				temp = first;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				// at the end "temp" points to last node

				temp2 = first;
				while(temp2->next != temp)
				{
					temp2 = temp2->next;
				}
				// At the end "temp2" points to second-last node
				temp2->next = NULL;
				free(temp);
				printf("Last Node is Removed from List\n");
				break;
			case 3: // Removing selected node.
				printf("Enter element of that Node, which you want to Remove : ");
				scanf("%d", &sel_ele);
				temp = first;
				while(temp->ele != sel_ele && temp!=NULL)
				{
					temp = temp->next;
				}

				if(temp == NULL)
				{
					printf("No Such node prsent.\n");
				}
				else
				{
					// means selected node found.
					// "temp" points to selected node.

					if(temp==first)
					{
						// selected node is first node
						first = first->next;
						free(temp);
					}
					else if(temp->next == NULL)
					{
						temp2 = first;
						while(temp2->next != temp)
						{
							temp2 = temp2->next;
						}
						// selected node is last node
						temp2->next =NULL;
						free(temp);
					}
					else
					{
						temp2 = first;
						while(temp2->next != temp)
						{
							temp2 = temp2->next;
						}
						temp2->next = temp->next;
						free(temp);
					}
					printf("Selected Node is Removed from List.\n");
				}
				break;
		} //end of switch-case
	    } //end of inner else
	} //end of outer else block
} // end of remove_node()


void display_list()
{
	struct Node *temp;
	if(first == NULL)
	{
		printf("List is Yet Not Created.\n");
	}
	else
	{
		temp = first;
		while(temp!=NULL)
		{
			printf("%d\t", temp->ele);
			temp = temp->next;
		}
		printf("\n");
	} //end of else
} //end of display_list()

void main()
{
	int ch;
	clrscr();
	first = NULL;

	do
	{
		clrscr();
		printf("\nSelect an option\n");
		printf("1 - Insert Node\n");
		printf("2 - Remove Node\n");
		printf("3 - Display List\n");
		printf("4 - EXIT\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: insert_node();
				getch();
				break;
			case 2: remove_node();
				getch();
				break;
			case 3: display_list();
				getch();
				break;
			case 4: exit(0);
		} //end of switch-case
	}while(1);

	getch();
}





















