#include<iostream>
using namespace std;

int power(int n,int p){

    if(n==0){
        return 0;
    }

    int prevPower = power(n,p-1);
    return n*prevPower;
}
//fibonacci number

// int fibo(int n){
//     if(n==0 || n==1){   //base case
//         return n;
//     }

//     return fibo(n-1) + fibo(n-2);
// }


int main()
{
    int n,p;
    cin>>n;

    cout<<power(n);

    return 0;
}