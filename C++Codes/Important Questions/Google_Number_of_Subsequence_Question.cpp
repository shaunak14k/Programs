//#include -> Preprocessor Directive (Used to include files)
//iostream -> Header File (Accepting input and printing output)
#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;



int main()
{
    int n;
    cin>>n;
    int array[n];

    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    
    int ans=2;
    int prevDiff=array[1]-array[0];
    int j=2;
    int currentDiff=2;

    while(j<n){
        if(prevDiff == array[j]-array[j-1])
            currentDiff++;
        else{
            prevDiff = array[j]-array[j-1];
            currentDiff=2;
        }

        ans = max(ans,currentDiff);
        j++;
    }

    cout<<ans;
   
    return 0;
}