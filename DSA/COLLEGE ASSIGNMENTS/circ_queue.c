#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
int entry;
struct node *next,*prev;
};

struct node *head;

int count;

void addbeg(int *x);
void addbetween(int *x);
void addatend(int *x);
void del(int *pos);
void display();
void init();
int empty();

struct node *np,*n,*p,*temp;

void main()
 {
	int ch,pos,x;
	char ans;
	clrscr();
	init();
	while(ch!=0)
	 {
	 printf("=====MENU=====\n\n");
	printf("\n1.Add at begining \n2.Add between \n3.Add at end\n4.Delete\n5.Display\n0.exit\n\nEnter your choice \n ");
	scanf("%d",&ch);
	switch(ch)
	 {
		case 1:
		 printf("\nEnter a number to insert in the list ");
		 scanf("%d",&x);
		 addbeg(&x);
		 break;
		case 2:
		 printf("\nEnter a number to insert in the list ");
		 scanf("%d",&x);
		 addbetween(&x);
		 break;
		case 3:
		 printf("\nEnter a number to insert in the list ");
		 scanf("%d",&x);
		 addatend(&x);
		 break;
		case 4:
			{
		 printf("\nEnter the position from 1 to %d to be deleted  ",count);
		 scanf("%d",&pos);
		 del(&pos);
		}
		 break;
		case 5:
		 printf("\nThe list is  \n\n");
		 display();
		 break;
		}
 }
}

void init()
 {
	head=NULL;
 }

int empty()
 {
	if(head==NULL)
		return 1;
	else
		return 0;
 }
void addatend(int *x)
 {

	int ch1;
	if (empty())
	printf("wrong choice");
	else
	{
	np=(struct node *)malloc(sizeof(struct node));
	np->entry=*x;
	np->next=NULL;

	for (p=head;p->next!=NULL;p=p->next);
	p->next=np;
	np->prev=p;
	}
	count++;
}
void addbeg(int *x)
 {
	int ch1;
	np=(struct node *)malloc(sizeof(struct node));
	np->entry=*x;
	np->next=NULL;
	np->prev=NULL;
	if(empty())
	{
	head=np;

	}
	else
	{
	np->next=head;
	head->prev=np;
	head=np;
	}
	count++;
}
void addbetween(int *x)
 {
	int i,pos;
	
	if (empty())
	printf("wrong choice");
	
	else
	{
	np=(struct node *)malloc(sizeof(struct node));
	np->entry=*x;
	np->next=NULL;

	printf("enter position where u want to enter");
	scanf("%d",&pos);
	
	if (pos<1||pos>count)
	printf("wrong position");
	
	else
	{
       	for (p=head,i=1;i<pos;i++,p=p->next) ;

	np->next=p->next;
	p->next->prev=np;
	p->next=np;
	np->prev=p;

	}
	}
}
void display()
 {
 node *t;
	for (p=head;p!=NULL;p=p->next)
	printf("%d\t",p->entry);
	//or
	for (p=head;p->next!=NULL;p=p->next);
	
	for (t=p;t!=head;t=t->prev)
	printf("%d\t",t->entry);
	printf("\n");
 }

void del(int *pos)
 {
 int i;
	if(*pos <= 0 || *pos > count)
	 {
	printf("\n%d Position does not exist  ",*pos);
	 }
	else
	 {
	temp=head;
	if(*pos==1)
	 {
		head=temp->next;
		printf("\nElement %d at the position %d has been deleted  ",temp->entry,*pos);
		free(temp);
	 }
	else
	 {
	for(i=1;i < *pos-1;i++)
	 {
	temp=temp->next;
	 }
	n=temp->next;
	temp->next=n->next;
	printf("\nElement %d at the position %d has been deleted  ",n->entry,*pos);
	free(n);
	 }  //  pos != 1
	count--;
	 }  //  position exists
 }
