//find if a number is a power of 2
#include<iostream>
using namespace std;

int isPowerof2(int n){
    return (n && !(n & (n-1))); //we put n && in the beginning to check when n is 0. Anything & 0 is 0;
}

int main()
{
    int n;
    cin>>n;
    cout<<isPowerof2(n)<<endl;
    return 0;
}