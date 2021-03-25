//#include -> Preprocessor Directive (Used to include files)
//iostream -> Header File (Accepting input and printing output)
#include<iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;



int main()
{
    // int a=10;
    // int* aptr=&a;
    // cout<<aptr<<endl;
    // cout<<*aptr<<endl;   
    // cout<<a<<endl; 
    
    //Printing array using pointer
    // int a[]={10,20,30};
    // cout<<*a<<endl;
    // int* ptr = a;

    // for(int i=0;i<3;i++){
    //     cout<<*ptr<<" ";
    //     ptr++;
    // }

    // //Dynamic Memory
    // int *p = new int();
    // *p = 10;
    // cout<<p<<endl;
    // delete(p);
    
    // p = new int[4];
    // p[0] = 20;
    // cout<<p[0]<<endl;

    string a="123";
    cout<<a+"10"<<endl;
    int b=1;
    float x = 1.2;
    char c='a';
    cout<<x+b;

    return 0;
}