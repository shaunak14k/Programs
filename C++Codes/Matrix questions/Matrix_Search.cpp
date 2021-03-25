#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
    //MATRIX SEARCH ALGO
    int target;
    cin>>target;

    bool flag=false;
    
    int r = 0, c = m-1;
    while(r<n && c>=0){
        if(a[r][c]==target){
            flag=true;
            break;
        }
        else if(a[r][c]>target){
            c--;
        }
        else 
            r++;
    }

    if(flag){
        cout<<"FOUND";
    }
    else{
        cout<<"Not found";
    }


    return 0;
}