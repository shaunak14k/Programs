// linked list

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int roll;  
    float perc; 
    struct node* next;
};

struct node* front = -1;
struct node* rear = -1;

void insertElements();
void deleteElements();
void print();
void printInOrder();

int main()
{
    //system("cls");

    head = NULL;    // empty list 

    int n, choice;
    int i;

    while(1)
    {
        system("cls");

        printf("\n *** CIRCULAR QUEUE *** \n");
        printf("\n 1. Add element ");
        printf("\n 2. Delete elemente");
        printf("\n 3. Print elements ");
        printf("\n 4. Exit");

        printf("\n\n Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insertElements();
                    break;

            case 2: deleteElements();
                    break;
            
            case 3: print();
                    break;
            
            case 4: //exit(0);

            default:    printf("\n Invalid option \n");
        }   

        printf("\n\n\n \t ** Enter any key to continue.. **");
        getch();
    }

    return 0;
}

struct node* createNode()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));    //create temperory node
    int roll;
    float perc;

    printf("\n Enter the roll number : ");
    scanf("%d",&roll);
    printf(" Enter the percentage : ");
    scanf("%f",&perc);

    temp->roll = roll;  // assign rollNO
    temp->perc = perc;  // assign percentage
    temp->next = NULL;  // temp points to 1st node of previous list 

    return temp;
}

void insertAtBeg()
{
    struct node* temp = createNode();
    
    // if queue is empty
    if(rear == -1)
    {
        front = rear = temp; 
        rear->next = front;   
    }
    else
    {
        rear->next = temp;
        rear = newnode;
    }

    printf("\n Data entered successfully");
}

void insertAtEnd()
{
    struct node* temp = createNode();
    struct node* last;

    // if list is empty
    if(head == NULL)
    {
        head = temp;    // head now points to temp. temp has become first node
    }

    else
    {
        last = head;   
        // traverse the linked list until last node
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp; // last node of list now points to new temp node hence temp has become last node
    }

    printf("\n Data entered successfully");
}

void insertAtPosition()
{
    struct node* temp = head;
    int key, count=0;

    printf("\n\n Enter the position to enter element : ");
    scanf("%d",&key);

    // Count number of nodes
    while(temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    // Check if key is valid
    if(key<0 || key>count)
    {
        printf("\n Invalid position");
        return;
    }

    struct node* np = createNode();

    temp = head;
    int i=1;
    while(i < key-1)
    {
        temp = temp->next;
        i++;
    }
    np->next = temp->next;
    temp->next = np;
   
    printf("\n Data entered successfully");
}


void deleteFirstNode()
{
    struct node *first = head;

    // if linked list is empty
    if(head == NULL)
    {
        printf("\n List is empty..");
        return;
    }
    // when list is not empty
    else
    {
        printf("\n\n Node is deleted : Roll no : %d    Percentage : %0.2f ",head->roll,head->perc);
        head = head->next;  // head now points to 2nd node of previous list
        free(first);    // free first node
    }
    printf("\n Node deleted successfully");
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
    else if(head->next == NULL)
    {
        printf("\n\n Node is deleted : Roll no : %d    Percentage : %0.2f ",head->roll,head->perc);
        free(head);
        head = NULL;
    }

    // when list is not empty
    else
    {
        // traverse until second last node 
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        last = temp->next;  // make a last node
        printf("\n\n Node is deleted : Roll no : %d    Percentage : %0.2f ",last->roll,last->perc);

        temp->next = NULL;  //second last node of previous now points to NULL as it has become last node is new list

        free(last); //free last node
    }
    printf("\n Node deleted successfully");
}

void deleteAtPosition()
{
    struct node* np = (struct node*)malloc(sizeof(struct node));    //create temperory node
    struct node* temp = head;
    int roll, key, count=0;
    float perc;

    printf("\n\n Enter the position to enter element : ");
    scanf("%d",&key);

    // Count number of nodes
    while(temp->next != NULL)
    {
        temp = temp->next;
        count++;

    }
    // Check if key is valid
    if(key<0 || key>count)
    {
        printf("\n Invalid position");
        return;
    }

    temp = head;
    int i=1;
    if(key == 1)
    {
        head = temp->next;
		printf("\n Element at the position %d has been deleted  ",key);
		free(temp);

    }
    else
    {
        while(i < key-1)
        {
            temp = temp->next;
            i++;
        }
        np = temp->next;
        temp->next = np->next;
        printf("\n Element at the position %d has been deleted  ",key);
        free(np);
    }
   
    printf("\n Data entered successfully");
}

void greatestElement()
{
    int a;
    int i;
    struct node* temp;
    struct node* highestNode;

    // if list is emptyu
    if(head == NULL)
    {
        printf("\n List is empty..\n");
        return;
    }

    if(head->next == NULL)
    {
        printf("\n Only one node is present in the list \n");
        return;
    }

    temp = head;
    float max = temp->perc;

    while(temp != NULL)
    {
        if(max < temp->perc)
        {
            max = temp->perc;
            highestNode = temp;
        }
        temp = temp->next;
    }

    printf("\n\n Student data with highest percentage :- ");
    printf("\n Roll no : %d \t Percentage : %f",highestNode->roll,highestNode->perc);

    free(highestNode);
}

void sortElements()
{
    struct node *current = head;
    struct node* index = NULL;
    int temp;

    // if list is empty
    if(head == NULL)
    {
        printf("\n List is empty..\n");
        return;
    }

    while(current != NULL)
    {
        index = current->next;

        while(index != NULL)
        {
            if(current->roll > index->roll)
            {
                temp = current->roll;
                current->roll = index->roll;
                index->roll = temp;
            }
            index = index->next;
        }
        
        current = current->next;
    }

    printf("\n\n Data is sorted by roll no. ");
    
}

void reverseList()
{
    struct node* prevNode, *nextNode, *temp;
    prevNode = nextNode = NULL;

    // if list is empty
    if(head == NULL)
    {
        printf("\n List is empty..\n");
        return;
    }

    while(head != NULL)
    {
        // reversing of points
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    head = prevNode; 

    printf("\n\n List is reversed successfully ");
}

void print()
{
    struct node* temp = head;
    printf("\n Student :- \n");
    //if linked list is empty
    if(head == NULL)
    {
        printf("\n List is empty..");
        return;
    }
    while(temp != NULL)
    {
        printf("\n Roll no : %d \t Percentage : %0.2f ",temp->roll,temp->perc);
        temp = temp->next;
    }
    printf("\n");

}
void printInOrder()
{
    struct node* temp = head;
    printf("\n Student :- \n");
    while(temp != NULL)
    {
        printf("\n Roll no : %d \t Percentage : %0.2f ",temp->roll,temp->perc);
        temp = temp->next;
    }
    printf("\n");

}