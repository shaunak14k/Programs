#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s1="my NAME is AA";

    //Convert to upper case
    for(int i=0;i<s1.size();i++){
        if(s1[i] >= 'a' && s1[i]<='z'){
            s1[i]-=32;
        }
    }
    cout<<s1<<endl;

    //Convert to lower case
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A' && s1[i]<='Z'){
            s1[i]+=32;
        }
    }
    cout<<s1<<endl;

    //by using inbuilt function
    string s2 = "in buit FUNCTION";
    cout<<endl<<s2<<endl;

    transform(s2.begin(),s2.end(),s2.begin(),:: tolower);
    cout<<s2<<endl;
    s2[1]='a';
    cout<<s2;

    return 0;
}