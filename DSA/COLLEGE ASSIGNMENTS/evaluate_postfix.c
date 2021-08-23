#include<stdio.h>
#include<ctype.h>
#include<conio.h>

#define MAX 20  //size of stack

// Structure for stack
typedef struct stack 
{
    int data[MAX];
    int top;
    
}stack;

int evaluate(char ,int ,int );
void init (stack *);
int empty(stack *);
int full(stack *);
void push(stack *,int );
int pop(stack *);

int main() 
{
    //system("CLS");

    stack s;
    char x;
    int op1,op2,val;
    init(&s);   // initialize stack top value

    printf("\n Enter any Postfix Expression : ");
    while(((x=getchar())!='\n'))    //Read character by character until enter is hit
    {
        if(full(&s)==1)
        { 
            printf("\n\n Stack is full. Please enter less than 20 elements");
            main();
        }

        if(isdigit(x))  // IF its a digit then push to the stack
            push(&s,x-48);  
        else    // ELSE when it is an Operator 
        {
            // get last 2 values(operands) and perform operation using evaluate() 
            op2 = pop(&s);
            op1 = pop(&s);

            val = evaluate(x,op1,op2);
            push(&s,val);   // push the evaluated value in stack
        }
    }
   
    val=pop(&s);    // get the last value from stack (final answer)
    printf("\n Answer = %d ",val);

    printf("\n\n");
    getch();

    return 0;
}

int evaluate(char x,int op1,int op2) 
{
    if(x=='+') 
        return (op1+op2);
    if(x=='-') 
        return (op1-op2);
    if(x=='*') 
        return (op1*op2);
    if(x=='/') 
        return (op1/op2);
    if(x=='%')
        return (op1%op2);    
}

void init (stack *s) 
{
    s->top=-1;
}

// check if stack is full
int full(stack *s) 
{
    if(s->top == MAX-1)
        return (1);
    return (0);
}

void push(stack *s,int x) 
{
    s->top = s->top+1;  // increment top
    s->data[s->top] = x;    // push value into stack
}

int pop(stack *s) 
{
    // get last value and return that value
    int x;
    x=s->data[s->top];
    s->top = s->top-1;
    return x;
}