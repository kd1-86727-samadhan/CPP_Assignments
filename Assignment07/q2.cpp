#include <iostream>
using namespace std;

class Employee
{
    int empId;
    double salary;

public:
    Employee()
    {
        this->empId = 0;
        this->salary = 0;
    }

    Employee(int eid, double salary)
    {
        this->empId = eid;
        this->salary = salary;
    }

    void setId(int eid)
    {
        this->empId = eid;
    }

    int getId()
    {
        return this->empId;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return this->salary;
    }

    virtual void accept()
    {
        cout << "\nEnter the employee id: ";
        cin >> this->empId;

        cout << "\nEnter the salary: ";
        cin >> this->salary;
    }

    virtual void display()
    {
        cout << "\nEmployee Id: " << this->empId;
        cout << "\nSalary: " << this->salary;
    }
}; // Employee

class Manager : virtual public Employee
{
    double bonus;

protected:
    void acceptManager()
    {
        cout << "\nEnter the bonus: ";
        cin >> this->bonus;
    }

    void displayManager()
    {
        cout << "\nBonus: " << this->bonus;
    }

public:
    Manager()
    {
        // cout << "\nManager()";
        this->bonus = 0;
    }

    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return this->bonus;
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
}; // Manager

class Salesman : virtual public Employee
{
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "\nEnter the commission: ";
        cin >> this->commission;
    }

    void displaySalesman()
    {
        cout << "\nCommission: " << this->commission;
    }

public:
    Salesman()
    {
        // cout << "\nSalesman()";
        this->commission = 0;
    }

    Salesman(int eid, double salary, double commission) : Employee(eid, salary)
    {
        this->commission = commission;
    }

    void setCommission(double comm)
    {
        this->commission = comm;
    }

    double getCommission()
    {
        return this->commission;
    }

    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }
}; // Salesman

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        // cout << "\nSalesManager()";
    }

    SalesManager(int eid, double salary, double bonus, double commission) : Employee(eid, salary)
    {
        // this->setBonus(bonus);
        // this->setCommission(commission);
    }

    void accept()
    {
        Employee::accept();
        this->acceptManager();
        this->acceptSalesman();
    }

    void display()
    {
        Employee::display();
        this->displayManager();
        this->displaySalesman();
    }
}; // SalesManager

int menuChoice()
{
    int mChoice;
    cout<<"\n*********************************************************************";
    cout<<"\n0. Exit";
    cout<<"\n1. Accept Employee";
    cout<<"\n2. Display the count of all employees with respect to designation";
    cout<<"\n3. Display All Manager";
    cout<<"\n4. Display All Salesman";
    cout<<"\n5. Display All SalesManagers";
    cout<<"\n*********************************************************************";
    cout<<"\n\nEnter your choice: ";
    cin>>mChoice;
    return mChoice;
}

int addEmployee()
{
    int ch;
    cout<<"\n***********************";
    cout<<"\n0. Exit";
    cout<<"\n1. Accept Manager";
    cout<<"\n2. Accept Salesman";
    cout<<"\n3. Accept SalesManager";
    cout<<"\n***********************";
    cout<<"\n\nEnter your choice: ";
    cin>>ch;
    return ch;
}


void displayCount(Employee **arr, int index)
{  
    int mCount = 0, sCount = 0, smCount = 0;
    for(int i = 0; i < index; i++)
    {
        if(typeid(*arr[i]) == typeid(Manager))
        {
            mCount++;
        }
        else if(typeid(*arr[i]) == typeid(Salesman))
        {
            sCount++;
        }
        else
        {
            smCount++;
        }
    }   // for

    cout<<"\nTotal number of employees: "<<index;
    cout<<"\nManager as a Employee: "<<mCount;
    cout<<"\nSalesman as a Employee: "<<sCount;
    cout<<"\nSalesManager as a Employee: "<<smCount;

}
int main()
{
    Employee *arr[5];
    int i, index = 0;
    int choice;
    while((choice = menuChoice()) != 0)
    {
        switch(choice)
        {
            case 1:
                {
                    int ch;
                    while((ch = addEmployee()) != 0)
                    {
                        switch(ch)
                        {
                            case 1:
                            {
                                cout<<"\nManager";
                                if(index < 5)
                                {
                                        arr[index] = new Manager;
                                        arr[index]->accept();
                                        index++;
                                }
                                else
                                {
                                    cout<<"\nArray is full....";
                                }
                            }
                            break;

                            case 2:
                                {
                                    cout<<"\nSalesman";
                                    if(index < 5)
                                    {
                                            arr[index] = new Salesman;
                                            arr[index]->accept();
                                            index++;
                                    }
                                    else
                                    {
                                        cout<<"\nArray is full....";
                                    }
                                }
                                break;

                            case 3:
                                {
                                    cout<<"\nSalesManager";
                                    if(index < 5)
                                    {
                                            arr[index] = new SalesManager;
                                            arr[index]->accept();
                                            index++;
                                    }
                                    else                               
                                    {
                                        cout<<"\nArray is full....";
                                    }
                                }
                                break;

                            default:
                                cout<<"\nInvalid Choice !!!!";
                                break;    
                        }   // inner switch
                    }   // inner while
                }
                break;

            case 2:
                {
                    cout<<"\nDisplay Count";
                    displayCount(arr, index);
                }
                break;
       
            case 3:
                {
                    cout<<"\nDisplay Managers";
                    for(i = 0; i < index; i++)
                    {
                        if(typeid(*arr[i]) == typeid(Manager))
                        {
                            arr[i]->display();
                        }
                    }
                }
                break;
            
            case 4:
                {
                    cout<<"\nDisplay Salesman";
                    for(i = 0; i < index; i++)
                    {
                        if(typeid(*arr[i]) == typeid(Salesman))
                        {
                            arr[i]->display();
                        }
                    }
                }
                break;
            
            case 5:
                {
                    cout<<"\nDisplay SalesManagers";
                    for(i = 0; i < index; i++)
                    {
                        if(typeid(*arr[i]) == typeid(SalesManager))
                        {
                            arr[i]->display();
                        }
                    }
                }
                break;
                
            default:
                cout<<"\nInvalid Choice !!!!";
                break;    
        }   // Outer switch
    }   // while

    for(i = 0; i < index; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }
    return 0;
}

