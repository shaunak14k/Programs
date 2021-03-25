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

    //SPIRAL PRINTING

    int rowStart = 0, rowEnd = n-1;
    int colStart = 0, colEnd = m-1;

    while(rowStart<=rowEnd && colStart<=colEnd)
    {
        //For row start
        for(int col=colStart; col<=colEnd; col++){
            cout<<a[rowStart][col]<<" ";
        }
        rowStart++;

        //For column end
        for(int row=rowStart; row<=rowEnd; row++){
            cout<<a[row][colEnd]<<" ";
        }
        colEnd--;

        //For row end
        for(int col=colEnd; col>=colStart; col--){
            cout<<a[rowEnd][col]<<" ";
        }
        rowEnd--;

        //For column start
        for(int row=rowEnd; row>=rowStart; row--){
            cout<<a[row][colStart]<<" ";
        }
        colStart++;
        
    }

    return 0;
}