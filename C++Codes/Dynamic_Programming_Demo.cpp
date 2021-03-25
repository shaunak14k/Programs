#include<iostream>
using namespace std;

int main()
{
     //Dynamic Memory
    int *p = new int();
    *p = 10;
    cout<<p<<endl;
    delete(p);
    
    p = new int[4];
    p[0] = 20;
    cout<<p[0]<<endl;

    int *a[10];
    *a[0]=10;
    return 0;
}