#include <iostream>
using namespace std;

class Employee
{
    int empId;
    double salary;

public:
    Employee()
    {
        cout << "\nEmployee()";
        this->empId = 0;
        this->salary = 0;
    }

    Employee(int eid, double sal)
    {
        this->empId = eid;
        this->salary = sal;
    }

    void setId(int eid)
    {
        this->empId = eid;
    }

    int getId()
    {
        return this->empId;
    }

    void setSalary(double sal)
    {
        this->salary = sal;
    }

    int getSalary()
    {
        return this->salary;
    }

    void acceptEmployee()
    {
        cout << "\nEnter the id: ";
        cin >> this->empId;

        cout << "\nEnter the salary: ";
        cin >> this->salary;
    }

    void displayEmployee()
    {
        cout << "\nId<<\t\tSalary";
        cout << "\n"
             << this->empId << "\t" << this->salary;
        cout << "\nSalary: " << this->salary;
    }
}; // Employee

class Manager : virtual public Employee
{
    double bonus;

public:
    Manager() : Employee()
    {
        cout << "\nManager()";
        this->bonus = 0;
    }

    Manager(double bn, int id, double sal) : Employee(id, sal)
    {
        this->bonus = bn;
    }

    void setBonus(double bn)
    {
        this->bonus = bn;
    }

    double getBonus()
    {
        return this->bonus;
    }

    void acceptManager()
    {
        Employee::acceptEmployee();
        cout << "\nEnter the bounus: ";
        cin >> this->bonus;
    }

    void displayManager()
    {
        Employee::displayEmployee();
        cout << "\nBonus: "
             << "\n"
             << bonus;
    }
}; // Manager

class Salesman : virtual public Employee
{
    double commission;

public:
    Salesman() : Employee()
    {
        cout << "\nSalesman()";
        this->commission = 0;
    }

    Salesman(double comm, int eid, double sal) : Employee(eid, sal)
    {
        this->commission = comm;
    }

    void setCommission(double comm)
    {
        this->commission = comm;
    }

    double getCommission()
    {
        return this->commission;
    }

    void acceptSalesman()
    {
        Employee::acceptEmployee();
        cout << "\nEnter the commission: ";
        cin >> this->commission;
    }

    void displaySalesman()
    {
        Employee::displayEmployee();
        cout << "\nCommission: " << this->commission;
    }
}; // Salesman

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "\nSalesManager()";
    }

    void acceptSalesman()
    {
    }

    void displaySalesman()
    {
    }

}; // SalesManager

int main()
{
    // Manager m1;
    // m1.acceptManager();
    // m1.displayManager();

    SalesManager s1;

    s1.acceptSalesman();
    s1.displaySalesman();

    return 0;
}