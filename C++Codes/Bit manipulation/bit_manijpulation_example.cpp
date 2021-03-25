#include<iostream>
using namespace std;

int getBit(int n,int pos){
    return ((n & (1<<pos))!=0); //return 1 if bit is present at given position 0 if not 
}
int setBit(int n,int pos){
    return (n | (1<<pos));  //return number after setting (1)bit at given position
}
int clearBit(int n,int pos){
    int mask = ~(1<<pos);
    return (n & mask);  //return the number after clearing the bit
}
int updateBit(int n,int pos,int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (value<<pos));
    return 1;
}

int main()
{
    int n,pos;
    cin>>n>>pos;

    cout<<"Get Bit - "<<getBit(n,pos)<<endl;
    cout<<"Set Bit - "<<setBit(n,1)<<endl;
    cout<<"Clear Bit - "<<clearBit(n,pos)<<endl;
    cout<<"Update Bit - "<<updateBit(n,1,1)<<endl;

    return 0;
}