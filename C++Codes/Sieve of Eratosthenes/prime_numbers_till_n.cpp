//Sieve of Eratosthenes
//Start from first prime number i(2), then mark all the multiples of it until n starting from the square of (2)
//Then start from square of i*i(4) then repeat
//All the unmarked numbers will be prime numbers

#include<iostream>
using namespace std;

void primeSieve(int n){

    int prime[n]={0};
    
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1; //1 means that element is marked. 0 is unmarked.
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    primeSieve(n);

    return 0;
}