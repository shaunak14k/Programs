// nonwrapSum use kedanes algo
//wrapsum add total sum and kedane algo for elements with sign reversed.

#include<iostream>
#include<math.h>
#include<cmath>
#include<climits>
using namespace std;

int kedane(int a[],int n){
    int currentSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        currentSum+=a[i];
        if(currentSum<0)
            currentSum=0;

        maxSum=max(maxSum,currentSum);
    }

    return maxSum;
}

int main()
{
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int nonwrapSum = kedane(a,n);
    int wrapSum;

    int totalSum = 0;
    for(int i=0;i<n;i++){
        totalSum+=a[i];
        a[i]=-a[i];
    }
    wrapSum = totalSum + kedane(a,n);

    cout<<max(wrapSum,nonwrapSum)<<endl;

    return 0;
}