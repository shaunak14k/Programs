#include<iostream>
using namespace std;

int firstOccr(int arr[],int n,int i,int key){

    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstOccr(arr,n,i+1,key);
}

int lastOccr(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    int restOfArray = lastOccr(arr,n,i+1,key);
    if(restOfArray!=-1){
        return restOfArray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}

int main()
{
    int n=7,key;
    int arr[]={1,2,4,1,6,2,1};
    cin>>key;

    cout<<firstOccr(arr,n,0,key)<<endl;  
    cout<<lastOccr(arr,n,0,key)<<endl;  

    return 0;
}