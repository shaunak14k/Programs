//First we sort the elements
//then put a low and high on a[0] and a[n=1] 
// compare sum of low and high with k is less then high-- if more then low++

#include<iostream>
#include<climits>
using namespace std;

bool pairSum(int a[],int n,int k){
    int low=0;
    int high=n-1;

    while(low<high){
        if(a[low]+a[high]==k){
            cout<<low<<"  "<<high<<endl;
            return true;
        }
        else if(a[low]+a[high]<k){
            low++;
        }
        else 
            high--;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    //Using insertion sort we will sort the elements
    for(int i=1;i<n;i++){
        int current = a[i];
        int j = i-1;
        while(a[j]>current && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = current; 
    }

    cout<<pairSum(a,n,k)<<endl;



    return 0;
}