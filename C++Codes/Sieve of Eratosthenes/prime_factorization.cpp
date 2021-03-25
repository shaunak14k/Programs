// Take smallest prime number (spf) of n and then divide it from n;
// Change the value of n to n = spf/n until n=1;
// Then find the spf of new n divide it with its spf
// All the spfs we found will be the prime factors of n

#include<iostream>
using namespace std;

void prmieFactor(int n){

    int spf[n]={0};
    
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    
    while(n!=1){
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
}

int main()
{
    int n;
    cin>>n;
    prmieFactor(n);
    return 0;
}