#include<iostream>
#include<string>
using namespace std;
int sum(int number)
{
    int sum=0;
    while(number > 0)
    {
        sum = sum + number%10;
        number = number/10;
    }
    return sum;
}
int count(int number)
{
    int count=0;
    while(number > 0)
    {
        number = number/10;
        count++;
    }
    return count;

}
int reverse()
{
    
}
int peledrome()
{

}
int main()
{
    int number;
    cout << "enter a number-:";
    cin>> number;
    cout<< sum(number) << endl;;
    cout<< count(number) << endl;
}
