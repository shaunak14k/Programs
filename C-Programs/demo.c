#include<stdio.h>
#incldue<stdlib.h>
#include<string.h>

int mem[100],reg[4],cond[]={0,0,0,0,0,1},opc,op1,op2,pc;
FILE *fp;
char fname[20];

void load()
{
	printf("Enter file name : ");
	scanf("%s",fname);
	
	fp = fopen(fname,"r");
	
	if(fp==NULL)
	{
		printf("File not found\n",fname);
		exit(1);
	}
	while(fscanf(fp,"%d",&mem[pc]) != -1)
		pc++;
	
	fclose(fp);
}
void print()
{
	int i;
	for(i=0; i<pc; i++)
	{
		printf("06d \n",mem[i]);
	}
}
void run()
{
	int i;
	pc = 0;
	
	while(1)
	{
		opc = mem[pc]/10000;
		op1 = mem[pc]%10000/10000-1;
		op2 = mem[pc]%1000;
		
		switch(opc)
		{
			//STOP
			case 0:	return;
			
			//ADD
			case 1:	reg[op1] += mem[op2];
					break;
					
			//SUB
			case 2:	reg[op1] -= mem[op2];
					break;
					
			//MULT
			case 3:	reg[op1] *= mem[op2];
					break;
					
			//DIV
			case 8:	reg[op1] /= mem[op2];
					break;
					
			//MOVER
			case 4:	reg[op1] = mem[op2];
					break;
					
			//MOVEM
			case 5:	mem[op2] = reg[op1];
					break;
					
			//COMP
			case 6:	if(reg[op1] < mem[op2])
						cond[0] = 1;
					
					if(reg[op1] <= mem[op2];
						cond[1] = 1;
					
					if(reg[op1] == mem[op2])
						cond[2] = 1;
					
					if(reg[op1] > mem[op2])
						cond[3] = 1;
					
					if(reg[op1] >= mem[op2])
						cond[4] = 1;
					break;
					
			//BC
			case 7:	if(cond[op1] == 1)
						pc = op2 - 1;
					
					for(i=0; i<5; i++)
						cond[i] = 0;
					break;
					
			//READ
			case 9:	printf("\n\n Enter the integer : ");
					scanf("%d"&mem[op2]);
					break;
					
			//PRINT
			case 10:	printf("%d\n",mem[op2]);
		}
		
		pc++;
	}
}
int main()
{
	printf(" 1. Load \n 2. Print \n 3. Run \n 4. Exit \n");
	printf("Enter your choice : ");
	scanf("%d",&ch);
	
	while(1)
	{
		switch(ch)
		{
			case 1:	load();
					break;
					
			case 2:	print();
					break;
				
			case 3:	run();
					break;
				
			case 4:	exit(0);
		}	
	}
	return 0;
}