// this code is to covert a decimal number to binary
#include<iostream>
using namespace std;
int decTobinary(int number)
{
    int ans=0;
    int pow=1;
    while(number>0)
    {
        int rem=number%2;
        number=number/2;
        ans = ans + (rem*pow);
        pow=pow*10;
    }
    return ans;
}
int binaryTodec(int bnum)
{
    int ans=0;
    int pow=1;
    while(bnum>0)
    {
        int rem=bnum%10;
        ans=ans+(rem*pow);
        bnum = bnum/10;
        pow=pow*2;
    }
    return ans;
}
int main()
{
    cout << decTobinary(42) << endl;
    cout << binaryTodec(101010) << endl;
    return 0;
}