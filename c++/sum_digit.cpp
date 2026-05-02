#include<iostream>
using namespace std;
int sumD(int n)
{
    int sum=0;
    while(n>0)
    {
        int last= n%10;
        n=n/10;
        sum=sum + last;
    }
    return sum;
}
int main()
{
    cout << " sum of digits of number is -:" << sumD(12345) ;
}