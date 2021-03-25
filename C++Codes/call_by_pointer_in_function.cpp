#include<iostream>
using namespace std;

int swap(int *p1,int *p2){
    int temp=*p1;
    *p1=*p2;
    *p2=temp;

    int sum=*p1+*p2;
    return sum;
}

int main()
{
    int a=2,b=4;
    
    int sum=swap(&a,&b);

    cout<<a<<b<<endl;
    cout<<sum<<endl;
    return 0;
}