#include<iostream>
using namespace std;

void decr(int n){

    if(n==0){
        return;
    }

    cout<<n<<endl;
    decr(n-1);
}

void incr(int n){

    if(n==0){
        return;
    }
    incr(n-1);
    cout<<n<<endl;
}

int main()
{
    int n;
    cin>>n;

    decr(n);
    incr(n);

    return 0;
}