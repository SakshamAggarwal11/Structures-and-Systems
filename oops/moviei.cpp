// Cinema Ticket Booking System
// Problem Statement
// Write a C++ program to manage ticket bookings for a single-screen cinema using a class.
// Design a class named Ticket with the following data members:
// • Movie Name
// • Seat Number
// • Customer Name
// • Ticket Price
// Requirements
// • Implement a member function bookTicket() to accept the details of a ticket from the user.
// • Implement a member function printTicket() to display the ticket details in a receipt-style format.
// • Implement a member function getPrice() to return the ticket price.
// • Create an array of 5 Ticket objects to represent bookings for one movie show.
// • Read the details of all 5 tickets using the bookTicket() function.
// • Display the receipt for each ticket using the printTicket() function.
// • Calculate and display the total revenue collected from all 5 ticket bookings.
// Constraints
// • Use a class to represent a ticket.
// • Use an array of objects to store ticket bookings.
// • Implement all operations using member functions.
// • Assume exactly 5 ticket bookings for the movie show
#include<iostream>
#include<string>
using namespace std;
class ticket {
    string movie_name;
    string cus_name;
    string seat_no;
    float price;
    public:
    void bookticket()
    {
        cout << "enter the movie name-:" ;
        cin >> movie_name;
        cout << "enter customer name-:" ;
        cin >> cus_name;
        cout << "enter seat number-:";
        cin >> seat_no;
        cout << "enter the ticket price-:";
        cin >> price;
    }
    float getprice()
    {
       return price;
    }
    void printticket()
    {
        cout << "\t\tReciept\t\t\n"<< endl;
        cout << "Movie name-\n" << movie_name << endl;
        cout << "customer name-\n" << cus_name<< endl;
        cout << "seat number-\n" << seat_no<< endl;
        cout << "ticket price-\n" << price<< endl;
        cout << "\n\t\tThanku visit again\t\t\n"<< endl;
    }
};
int main() {
    float total_revenue=0;
    ticket t[5];
    for(int i=0;i<5;i++)
    {
        t[i].bookticket();
    }
    for(int i=0;i<5;i++)
    {
        t[i].printticket();
    }
    for(int i=0;i<5;i++)
    {
        total_revenue= total_revenue + t[i].getprice();
    }
    cout << "Total revenue done is -:" << total_revenue ;
    return 0;
}