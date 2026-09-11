// Hospital Appointment Management System
// Problem Statement
// Write a C++ program to manage appointments in a hospital using a class named Appointment.
// The class should contain the following data members:
// • Patient Name
// • Age
// • Doctor Name
// • Appointment Time
// • Token Number
// Requirements
// • Implement a default constructor to initialize all data members with default values.
// • Implement a parameterized constructor to initialize an appointment at the time of object creation.
// • Implement a member function scheduleAppointment() to accept appointment details from the user.
// • Implement a member function displayAppointment() to display the details of an appointment.
// • Implement a member function isConflict(Appointment other) to check whether two appointments have
// the same doctor and the same appointment time. If both match, report an appointment conflict.
// • Create an array of 8 Appointment objects.
// • Initialize the first four appointments using the parameterized constructor.
// • Initialize the remaining four appointments using the default constructor and the scheduleAppointment()
// function.
// • Compare each newly created appointment with the previously created appointments and display any
// conflicts found.
// • Sort all appointments in ascending order of appointment time using the Bubble Sort algorithm.
// • Display the final appointment schedule in a tabular format. 
// Constraints
// • Use a class to represent an appointment.
// • Demonstrate the use of both default and parameterized constructors.
// • Use an array of objects to store appointments.
// • Use member functions to perform all operations.
// • Use the Bubble Sort algorithm to arrange appointments in ascending order of appointment time.
// • Assume a maximum of 8 appointments.
#include<iostream>
#include<string>
using namespace std;
class appointment
{
    private:
    string patient_name;
    int age;
    string doctor;
    int time;
    int token;
    public:
    appointment() 
    {
        patient_name="-";
        age=0;
        doctor="-";
        time=0;
        token=0;
    }
    appointment(string name, int Age , string Doctor , int Time , int Token)
    {
        patient_name= name;
        age=Age;
        doctor=Doctor;
        time=Time;
        token=Token;
    }
    void scheduleAppointment()
    {
        cout << "Enter your name-:" ;
        cin >> patient_name;
        cout << "Enter your age-:" ;
        cin >> age;
        cout << "Enter your doctor name-:";
        cin >> doctor;
        cout << "Enter the time of appointment-:";
        cin >> time;
        cout << "Enter the token number-:";
        cin >> token;
    }
    void displayAppointment()
    {
        cout << "Name-:" << patient_name << endl;
        cout << "Age-:" << age << endl;
        cout << "Doctor-:" << doctor << endl;
        cout << "Time-:" << time << endl;
        cout << "Token Number-:" << token << endl;
    }
    bool isconflict(appointment other)
    {
        if(doctor==other.doctor && time== other.time)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int TIME()
    {
        return time;
    }
};
int main()
{
    appointment a[8];
    a[0]=appointment("rehan",19,"rakesh",1900,1);
    a[1]=appointment("rohit",91,"ramesh",1800,2);
    a[2]=appointment("rahul",29,"sachdeva",1700,3);
    a[3]=appointment("akansh",12,"rakesh",1600,4);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i].isconflict(a[j])) // it will be either if(true) or if(false)
            {
                cout << "conflict found" << endl;
            }
        }
    }
    for(int i=4;i<8;i++)
    {
        a[i].scheduleAppointment();
        for(int j=0;j<i;j++)
        {
            if(a[i].isconflict(a[j]))
            {
                cout << "conflict found" << endl;
            }
        }
    }
    for(int i=0;i<8-1;i++)
    {
        for(int j=0;j<8-i-1;j++)
        {
            if(a[j].TIME()>a[j+1].TIME())
            {
                appointment temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout << "\t\t\t\tAPPOINTMENTS" << endl;
    for(int i=0; i<8; i++)
    {
        a[i].displayAppointment();
        cout<< "------------------------------------------------------------"<< endl;
    }
    return 0;
}