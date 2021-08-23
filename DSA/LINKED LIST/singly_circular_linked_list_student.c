// circular linked list

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int roll;  
    float perc; 
    struct node* next;
};

struct node* head;

struct node* createNode();
void insertAtEnd();
void insertAtBeg();
void deleteLastNode();
void deleteFirstNode();
void print();

int main()
{
    system("cls");

    head = NULL;    // empty list 

    int n, choice;
    int i;

    while(1)
    {
        //system("cls");

        printf("\n\n *** CIRCULAR SINGLY LINKED LIST *** \n");
        printf("\n 1. Add element at beginning");
        printf("\n 2. Add element at the end");
        printf("\n 3. Delete last node");
        printf("\n 4. Delete first node");
        printf("\n 5. Print elements ");
        printf("\n 6. Exit");

        printf("\n\n Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insertAtBeg();
                    break;

            case 2: insertAtEnd();
                    break;

            case 3: deleteLastNode();
                    break;

            case 4: deleteFirstNode();
                    break;
            
            case 5: print();
                    break;
            
            case 6: exit(0);

            default:    printf("\n Invalid option \n");
        }   

        //printf("\n\n\n \t ** Enter any key to continue.. **");
        //getch();
    }
}

struct node* createNode()
{
    struct node* np = (struct node*)malloc(sizeof(struct node));    // create a temporary node 

    int roll;
    float perc;

    printf("\n Enter the roll number : ");
    scanf("%d",&roll);
    printf(" Enter the percentage : ");
    scanf("%f",&perc);

    // assign values in temp node
    //np->next = NULL;
    np->roll = roll;
    np->perc = perc;

    return np;
}

void insertAtEnd()
{
    struct node* temp = head;   // create copy of first node (head)
    struct node* np = createNode();
    
    // if linked list is empty
    if(head == NULL)
    {
        np->next = np;  // link the node to itself
        head = np;     // assign new node to head (make np as head node)
    }

    // when list is not empty
    else
    {
        // traverse until last node (that points to the first node-head)
        while(temp->next != head)
        {
            temp = temp->next;
        }
        np->next = head; //(temp->link)  // np's link will now point to head (np has become last node)
        temp->next = np;    // temp is now second last node and points to np (last node)
    }

    printf("\n Data entered successfully");
}

void insertAtBeg()
{
    struct node *temp = head;
    struct node* np = createNode();

    // if linked list is empty
    if(head == NULL)
    {
        np->next = np;  // link the node to itself
        head = np;     // assign new node to head (make np as head node)
    }

    // when list is not empty
    else
    {        
        // traverse until last node (that points to the first node-head)
        while(temp->next != head)
        {
            temp = temp->next;
        }
        np->next = head; //(temp->link)  // np's link will now point to head (np has become last node)
        temp->next = np;    // temp is now second last node and points to np (last node)
        head = np;  // head now points to np (np has become 1st node)
    }

    return;
}

void deleteLastNode()
{
    struct node *temp = head;
    struct node *last;

    // if linked list is empty
    if(head == NULL)
    {
        printf("\n List is empty..");
        return;
    }

    // only 1 node is present
    else if(head->next == head)
    {
        printf("\n\n Node is deleted : Roll no : %d    Percentage : %0.2f ",head->roll,head->perc);
        free(head);
        head = NULL;
    }

    // when list is not empty
    else
    {
        // traverse until second last node 
        while(temp->next->next != head)
        {
            temp = temp->next;
        }
        
        last = temp->next;  // make a last node
        printf("\n\n Node is deleted : Roll no : %d    Percentage : %0.2f ",last->roll,last->perc);

        temp->next = head;  //second last node points to head

        free(last); //free last node
    }

    printf("\n Node deleted successfully");
}

void deleteFirstNode()
{
    struct node *first = head;
    struct node *last = head;

    // if linked list is empty
    if(head == NULL)
    {
        printf("\n List is empty..");
        return;
    }

    // only 1 node is present
    else if(head->next == head)
    {
        printf("\n\n Node is deleted : Roll no : %d    Percentage : %0.2f ",head->roll,head->perc);
        free(head);
        head = NULL;
    }

    else
    {
        // traverse until last node 
        while(last->next != head)
        {
            last = last->next;
        }

        printf("\n\n Node is deleted : Roll no : %d    Percentage : %0.2f ",head->roll,head->perc);
        
        head = head->next;  // head(1st node) is now the second node
        last->next = head;  // last node points to new head that is 2nd node of previous list

        free(first);    // free first node
    }
}

void print()
{
    struct node *temp = head;
	if(head == NULL)
	{
		printf("\n List is empty....\n");
		return;
	}

    printf("\n Student :- \n");
	do
	{
		printf("\n Roll no : %d \t Percentage : %0.2f ",temp->roll,temp->perc);
		temp=temp->next;

	}while(temp != head);
}