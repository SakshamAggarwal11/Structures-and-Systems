#include<iostream>
using namespace std;
void pattern_1()
// output should be 
// 1 2 3 4....n
// 1 2 3 4
// .
// .
// .                   (m times)
// 1 2 3 4....n
{
    int n,m;
    cout << "enter how much lines you waant in row-:";
    cin >> n;
    cout << "enter how much line you want in column-:";
    cin >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << j ;
        }
        cout << endl;
    }
}
// similarly we can print star pattern also in this code by replacing j with star
void pattern_2()
// output shoud be
// A B C D ..... n-times
// A B C D
// .
// .
// .                         (m-times)
// A B C D ..... n-times
{
    int n,m;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    cout << "enter how much line you want in column-:";
    cin >> m;
    for(int i=1;i<=n;i++)
    {
        char ch='A';
        for(int j=1;j<=m;j++)
        {
            cout << ch ;
            ch=ch+1;
        }
        cout << endl;
    }
}
void pattern_3()
// output should be 
// 1 2 3 4....n
// 5 6 7 8
// .
// .
// .                   (m times)
{
    int n,m;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    cout << "enter how much line you want in column-:";
    cin >> m;
    int num=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << " " << num ;
            num=num+1;
        }
        cout << endl;
    }
}
void pattern_4()
// output shoud be
// A B C D ..... n-times
// E F G H
// .
// .
// .                         (m-times)
{
    int n,m;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    cout << "enter how much line you want in column-:";
    cin >> m;
    char ch='A';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << ch ;
            ch=ch+1;
        }
        cout << endl;
    }
}
void pattern_5()
// output should be
// *
// **
// ***
// ****
// *****
{
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern_6()
// output should be
// 1
// 22
// 333
// 4444
// 55555
{
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            cout << i+1;
        }
        cout << endl;
    }
}
void pattern_7()
// output should be 
// A
// BB
// CCC
// DDDD
// EEEEE
{
     int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char ch='A'+i;
        for(int j=1;j<=i+1;j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void pattern_8()
// output should be 
// 1
// 12
// 123
// 12345
{
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern_9()
// floyds triangle 
// output should be
// 1
// 2 3
// 4 5 6
// 7 8 9 10
{
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    int num=1;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            cout << " " << num;
            num=num+1;
        }
        cout << endl;
    }
}
void pattern_10()
{
    // OUTPUT SHOULD BE
    // A
    // B C
    // D E F G
    // H I J K L
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    char ch='A';
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            cout << ch;
            ch=ch+1;
        }
        cout << endl;
    }
}
void pattern_11()
{
    // OUTPUT SHOULD BE
    // A
    // B C
    // D E F G
    // H I J K L
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    char ch='A';
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j>=1;j--)
        {
            cout << ch;
            ch=ch+1;
        }
        cout << endl;
    }
}
// PATTERN 9,10,11 ARE FLOYFS TRIANGLE IN IT IF WE CHANGE INNER LOOP TO REVERSE THEN ALSO PATTERN WILL BE SAME
void pattern_12()
// OUTPUT SHOULD BE 
// 1
// 21
// 321
// 4321
// 54321
{
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j>0;j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern_13()
// OUTPUT SHOULD BE 
// A
// BA
// CBA
// DCBA
// EDCBA
{
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char ch='A'+i;
        for(int j=i+1;j>0;j--)
        {
            cout << ch;
             ch=ch-1;
        }
        cout << endl;
    }
}
void pattern_14()
// output should be
// 1 1 1 1 
//   2 2 2
//     3 3
//       4
{
    int n;
    cout << "enter how much lines you want in row-:";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
int main()
{
    pattern_1();
    pattern_14();
}