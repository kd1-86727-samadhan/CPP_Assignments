#include<iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

    public:
        // Default/Parameterless Constructor
        Date()
        {
            this->day = 1;
            this->month = 1;
            this->year = 2024;
        }

        // Parameterized Constructor
        Date(int day, int month, int year)
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }

        // Mutators - setter
        void setDay(int d)
        {
            this->day = d;
        }

        // Inspectors
        int getDay()
        {
            return this->day;
        }

        // Mutators - setter
        void setMonth(int m)
        {
            this->month = m;
        }

        // Inspectors
        int getMonth()
        {
            return this->month;
        }

        // Mutators - setter
        void setYear(int y)
        {
            this->year = y;
        }

        // Inspectors
        int getYear()
        {
            return this->year;
        }

        // Facilitator
        void acceptDate()
        {
            cout<<"\nEnter the day: ";
            cin>>this->day;

            cout<<"\nEnter the month: ";
            cin>>this->month;
            
            cout<<"\nEnter the year: ";
            cin>>this->year;
        }

        // Facilitator
        void displayDate()
        {
            cout<<"\nDate: "<<this->day<<"/"<<this->month<<"/"<<this->year;
        }
};  // Date

class Person
{
    string name;
    string address;
    Date dob;

    public:
        Person()    // Default/Parameterless Constructor
        {
            this->name = "\"\"";
            this->address = "\"\"";
        }

        // Parameterized Constructor
        Person(string nm, string add, int day, int month, int year)
        {
            this->name = nm;
            this->address = add;
            this->dob.setDay(day);
            this->dob.setMonth(month);
            this->dob.setYear(year);
        }

        // Facilitator
        void acceptPerson()
        {
            cout<<"\n\nEnter the person name: ";
            cin>>this->name;

            cout<<"\nEnter the person address: ";
            getchar();
            getline(cin, address);
            // cin>>this->address;

            dob.acceptDate();
        }

        // Facilitator
        void displayPerson()
        {
            cout<<"\n------------------------------------------------------";
            cout<<"\nPerson name\tAddress";
            cout<<"\n"<<this->name<<"\t\t"<<this->address;
    
            cout<<"\n\nDate of birth";
            dob.displayDate();
            cout<<"\n------------------------------------------------------";
        }
};  // Person

int main()
{
    Person p1;
    p1.displayPerson();

    Person p2;
    p2.acceptPerson();
    p2.displayPerson();
}
