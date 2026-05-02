// wap to calculate sum using recursion
#include<stdio.h>
int sum(int n)
{
    if (n==0)
    {
        return 0;
    }
    return sum(n-1)+n;
}
int main()
{
    int n=10;
    printf("sum of first %d natural number is-:%d",n,sum(n));
    return 0;
}