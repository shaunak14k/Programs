#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    string s1;
    cin>>s1;

    
    // sort(s1.end(),s1.begin());
    // cout<<s1;

    //USING MANUAL SORT AND THEN REVERSING THE NUMBER
    // //Selection sort
    // int n=s1.size();
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<=n-1;j++){
    //         if(s1[i]>s1[j]){
    //             char temp = s1[i];
    //             s1[i]=s1[j];
    //             s1[j]=temp;
    //         }
    //     }
    // }
    // cout<<s1<<endl;

    // int a = stoi(s1);

    // int ans=0;
    // while(a>0){
    //     int r = a%10;
    //     ans = (ans*10)+r;
    //     a/=10;
    // }
    // cout<<ans<<endl;

    //Another apporad using inbuilt funcion
    sort(s1.begin(),s1.end(),greater<int>());
    cout<<s1;


    return 0;
}