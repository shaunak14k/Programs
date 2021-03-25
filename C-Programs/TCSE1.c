#include<stdio.h>
#include<stdlib.h>

void main()
{
	int A[6] = {'0','1','1','0','1','0'};
	
	int i=0,temp,j;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	printf("\n Sorted : ");
	for(i=0;i<6;i++)
	{
		printf("%3d",A[i]);
	}
}