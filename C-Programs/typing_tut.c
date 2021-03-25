#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int main()
{
    int i,n;
    char ch[50];
    char str[5][20] = {"shaunak","tea","coffee","vodka","beer"};
    int count=0;
    n = 3;

    //system("CLS");

    for(i=0;i<5;i++)
    {
        
        printf(" Word - %s \n",str[i]);
  
        printf("\n -> ");
       
        delay(2);

        gets(ch);
        
    }

    printf("\n\n Number of correct words : %d",count);

    return 0;
}