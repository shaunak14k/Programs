#include<iostream>
using namespace std;

bool sorted(int arr[],int n){

    if(n==1){
        return true;
    }

    bool restOfArray = sorted(arr+1,n-1);
    return (arr[0]<arr[1] && restOfArray);

}

int main()
{
    int n=5;
    int arr[n]={1,2,23,4,5};

    cout<<sorted(arr,n);

    return 0;
}