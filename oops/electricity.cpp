// saksham aggarwal
// btech cse section b
#include<iostream>
using namespace std;


int calculateunits(int punits, int cunits)
    {
        return cunits - punits;
    }


int calculatebill(int units)
    {
        if(units<=100)
        {
            return 2*units;
        }
        else if(units<=200)
        {
            return 100 * 2 + (units-100) * 3;  
        }
        else
        {
            return 100 * 2 + 100 * 3 + (units - 200) * 5;
        }
    }


void displaybill(int unit, int bill)
    {
        cout<< "Total consumed " << unit << " Units" << endl;
        cout << "Total Bill = Rs. " << bill;
    }


int main()
{
    int currunits, prevunits, units, bill;
    cout<< "enter current units from meter: ";
    cin >> currunits;
    cout<< "enter previous units from meter: ";
    cin >> prevunits;
    units = calculateunits(prevunits, currunits);
    bill = calculatebill(units);
    displaybill(units, bill);
}