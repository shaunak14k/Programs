#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //BUBBLE SORT ALGO
    int counter=1;
    for(int j=0;j<n-1;j++)
    {
        for(int i=0;i<n-i-1;i++)
        {
            if(a[i]>a[i+1])
            {
                int temp=a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
    
    cout<<"\n Sorted - ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}