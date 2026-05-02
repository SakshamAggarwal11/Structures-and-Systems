#include<iostream>
using namespace std;
int main()
{
    char character;
    cout<<"enter the character of your choice" << endl;
    cin>> character;
    if(character >= 'A' && character <= 'Z')
    {
        cout<< "enterd character is a uppercase" << endl;
    }
    else if(character >= 'a' && character <= 'z')
    {
        cout<< "enterd character is a lowercase" << endl;
    }
    else if(character=='!'||character=='@'||character=='#'||character=='$'||character=='%'||character=='^'||character=='&'||character=='*'||character=='('||character==')'||character=='-'||character=='_'||character=='='||character=='+'||character=='~'||character=='['||character=='}'||character=='{'||character=='}'||character=='|'||character==';'||character==':'||character=='<'||character=='>'||character==','||character=='.'||character=='/'||character=='?')
    {
        cout<< "entered characte is a special character"<< endl;
    }
    else
    {
        cout<< "enterd value is a number"<< endl;
    }
    return 0;
}