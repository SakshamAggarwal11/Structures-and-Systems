// write a prog to calculate nth element of fibonacci series
#include<stdio.h>
int fibonacci(int n) // 0,1,1,2,3,5,8,13,21.............n
{
    if(n==1)
    {
        return 1;
    }
    else if (n==0)
    {
        return 0;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    printf("enter position of element in series-:");
    scanf("%d",&n);
    printf("value of fibonacci at enterd position is-:%d ",fibonacci(n));
    return 0;
}