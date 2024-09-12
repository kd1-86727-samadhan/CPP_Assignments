#include <iostream>
using namespace std;

int tollPaidByCar = 0;
int notTollPaidByCar = 0;

class TollBooth
{
    unsigned int totalNoOfCars;
    double amount;

public:
    TollBooth()
    {
        this->totalNoOfCars = 0;
        this->amount = 0;
    }

    TollBooth(unsigned int tnoc, double amt)
    {
        this->totalNoOfCars = tnoc;
        this->amount = amt;
    }

    void payingCar()
    {
        tollPaidByCar++;
        totalNoOfCars++;
        amount = amount + 50;
    }

    void notPayingCar()
    {
        notTollPaidByCar++;
        totalNoOfCars++;
    }

    void display()
    {
        cout<<"\n\t\t****Tollbooth at a bridge****";
        cout<<"\nPaying Cars\tNot Paying Cars\t\tTotal Collection Amount";
        cout << "\n"<<totalNoOfCars<<"\t\t\t"<<notTollPaidByCar<<"\t\t\t"<<amount<<"Rs.";
    }
};

int menuChoice()
{
    int mChoice;
    cout << "\n\n";
    cout << "+--------------------------------+" << endl;
    cout << "|                                |" << endl;
    cout << "|         ****Menu****           |" << endl;
    cout << "|                                |" << endl;
    cout << "+--------------------------------+" << endl;
    cout << "| 1. Paying Cars                 |" << endl;
    cout << "+--------------------------------+" << endl;
    cout << "| 2. Not Paying Cars             |" << endl;
    cout << "+--------------------------------+" << endl;
    cout << "| 3. Display                     |" << endl;
    cout << "+--------------------------------+" << endl;
    cout << "\nEnter your choice: ";
    cin >> mChoice;
    return mChoice;
}

int main()
{
    TollBooth tb1;
    int choice;

    while ((choice = menuChoice()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            tb1.payingCar();
        }
        break;

        case 2:
        {
            tb1.notPayingCar();
        }
        break;

        case 3:
        {
            tb1.display();
        }
        break;

        default:
            cout << "\nInvalid choice !!!!";
        } // switch
    }     // while
    return 0;
}