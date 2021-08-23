#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int roll;
    float perc;
    struct node *next;
    struct node *prev;
};

struct node *head;

struct node* createNode();
void insertAtEnd();
void insertAtBeg();
void deleteLastNode();
void deleteFirstNode();
void print();

int main()
{
    system("cls");
    int choice;
    while(1)
    {
        //system("cls");

        printf("\n\n *** DOUBLY LINKED LIST *** \n");
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

    return 0;
}

struct node* createNode()
{
    struct node* np = (struct node*)malloc(sizeof(struct node));   

    int roll;
    float perc;

    printf("\n Enter the roll number : ");
    scanf("%d",&roll);
    printf(" Enter the percentage : ");
    scanf("%f",&perc);

    np->roll = roll;
    np->perc = perc;
    np->next = NULL;
    np->prev = NULL;

    return np;
}

void insertAtEnd()
{
    struct node* temp = head;   
    struct node* np = createNode();
    
    // if linked list is empty
    if(head == NULL)
    {
        head = np;  
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    np->prev = temp;
    temp->next = np;

    printf("\n Data entered successfully");
   
    return;
}

void insertAtBeg()
{
    struct node* temp = head;   
    struct node* np = createNode();
    
    // if linked list is empty
    if(head == NULL)
    {
        head = np;  
        return;
    }

    head->prev = np;    // previous link of head to new node   
    np->next = head;    // next link of new node to head
    head = np;          // head now points to new node 

    printf("\n Data entered successfully");
   
    return;
}

void deleteLastNode()
{
    struct node* temp = head;
    struct node* last;

    // if linked list is empty
    if(head == NULL)
    {
        printf("\n List is empty..\n");  
        return;
    }

    if(head->next == NULL && head->prev == NULL)
    {
        printf("\n\n Element was deleted : Student : Roll no - %d \t Percentage - %f",head->roll,head->perc);
        free(head);
        head = NULL;

        return;
    }

    // traverse until 2nd last node
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    last = temp;
    last = last->next;  // go to last element
    
    temp->next = NULL;  //break link to last element
    
    printf("\n\n Element was deleted : Student : Roll no - %d \t Percentage - %f",last->roll,last->perc);
    //printf("\n Data deleted successfully");

    free(last);

    return;
}

void deleteFirstNode()
{
    struct node* temp = head;
    struct node* last;

    // if linked list is empty
    if(head == NULL)
    {
        printf("\n List is empty..\n");  
        return;
    }

    if(head->next == NULL && head->prev == NULL)
    {
        printf("\n\n Element was deleted : Student : Roll no - %d \t Percentage - %f",head->roll,head->perc);
        free(head);
        head = NULL;

        return;
    }

    // traverse until 2nd node
    temp = head->next;
    temp->prev = NULL;
    
    printf("\n\n Element was deleted : Student : Roll no - %d \t Percentage - %f",head->roll,head->perc);
    //printf("\n Data deleted successfully");

    free(head);
    head = temp;

    return;
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
		temp = temp->next;

	}while(temp != NULL);
}