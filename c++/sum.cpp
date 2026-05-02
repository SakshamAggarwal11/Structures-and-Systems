#include<iostream>
using namespace std;
int main()
{
    int n=10,sum_odd=0,sum_even=0;
    for(int i=0;i<=n;i++)
    {
        if(i%2!=0)
        {
            sum_odd=sum_odd+i;
        }
        else
        {
            sum_even=sum_even+i;
        }
    }
    int total_sum = sum_odd + sum_even;
    cout << "sum of first 10 odd number is-:" << sum_odd << endl;
    cout << "sum of first 10 even number is-:" << sum_even << endl;
    cout << "sum of first 10 numbers is-:" << total_sum << endl;
    return 0;
}