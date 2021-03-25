//#include -> Preprocessor Directive (Used to include files)
//iostream -> Header File (Accepting input and printing output)
#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;



int main()
{
    // int a=10;
    // int* aptr=&a;
    // cout<<aptr<<endl;
    // cout<<*aptr<<endl;   
    // cout<<a<<endl; 
    
    //Printing array using pointer
    int a[]={10,20,30};
    cout<<*a<<endl;
    int* ptr = a;

    for(int i=0;i<3;i++){
        cout<<*ptr<<" ";
        cout<<*(a+i)<<" ";
        ptr++;
    }

    return 0;
}