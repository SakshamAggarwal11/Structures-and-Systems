#include<iostream>
using namespace std;
int main()
{
    int target,prime;
    cout << "enter the number to check if it is prime or not-:" << endl;
    cin>>target;
   if( target==0 || target ==1)
    {
        prime=0;
    }
    for(int i=2;i<target;i++)
    {
        if(target%i == 0) 
        {
            prime=0;
            break ;
        }
        else
        prime =1;
    }
    prime==1 ? cout << "enterd number is a prime number" << endl: cout << "enterd number is not a prime number" << endl;
    return 0;
}