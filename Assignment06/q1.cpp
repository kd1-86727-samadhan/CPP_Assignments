#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 1;
        this->month = 1;
        this->year = 2002;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void setDay(int day)
    {
        this->day = day;
    }

    int getDay()
    {
        return this->day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    int getMonth()
    {
        return this->month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    int getYear()
    {
        return this->year;
    }

    void acceptDate()
    {
        cout << "\nEnter the day: ";
        cin >> this->day;

        cout << "\nEnter the month: ";
        cin >> this->month;

        cout << "\nEnter the year: ";
        cin >> this->year;
    }

    void displayDate()
    {
        cout << "\nDate: " << this->day << "/" << this->month << "/" << this->year;
    }
}; // Date

class Person
{
    string name;
    string address;
    Date dob;

public:
    Person()
    {
        this->name = "\"\"";
        this->address = "\"\"";
    }

    Person(string name, string address, int day, int month, int year)
    {
        this->name = name;
        this->address = address;
        dob.setDay(day);
        dob.setMonth(month);
        dob.setYear(year);
    }

    void acceptPerson()
    {
        cout << "\n\nEnter the name: ";
        cin >> this->name;

        cout << "\nEnter the address: ";
        cin >> this->address;

        dob.acceptDate();
    }

    void displayPerson()
    {
        cout<<"\nName: "<<this->name<<"\nAddress: "<<this->address;
        cout<<"\n\nBirthdate";
        dob.displayDate();
    }
}; // Person

class Employee : public Person
{
    int empId;
    double salary;
    string dept;
    Date doj;

    public:
        Employee()
        {
            this->empId = 1;
            this->salary = 0;
            this->dept = "\"\"";
        }

        Employee(int eid, string sal, string dept, int day, int month, int year) : doj(day, month, year)
        {
            this->empId = 1;
            this->salary = 0;
            this->dept = "\"\"";
            doj.setDay(day);
            doj.setMonth(month);
            doj.setYear(year);
        }

        void acceptEmployee()
        {
            this->acceptPerson();
            cout<<"\nEnter the id: ";
            cin>>this->empId;

            cout<<"\nEnter the salary: ";
            cin>>this->salary;   
            
            cout<<"\nEnter the department name : ";
            cin>>this->dept;

            doj.acceptDate();   
        }

        void displayEmployee()
        {
            this->displayPerson();
            cout<<"\n\nEmployee Details";
            cout<<"\nId: "<<this->empId;
            cout<<"\nSalary: "<<this->salary;
            cout<<"\nDepartment name: "<<this->dept;
            cout<<"\n\nDate of joining";
            doj.displayDate();
        }
};  // Employee

int main()
{
   
   Employee e1;
   e1.displayEmployee();
   
   Employee e2;
   e2.acceptEmployee();
   e2.displayEmployee();

    return 0;
}