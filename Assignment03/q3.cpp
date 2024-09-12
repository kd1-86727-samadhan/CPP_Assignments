#include <iostream>
using namespace std;

class Address
{
    string building;
    string street;
    string city;
    int pin;

public:
    Address()
    {
        // cout << "\nParameterless Constructor Called.";
        this->building = "\" \"";
        this->street = "\" \"";
        this->city = "\" \"";
        this->pin = 0;
    }

    Address(string bldg, string strt, string cty, int pn)
    {
        // cout << "\nParameterized Constructor Called.";
        this->building = bldg;
        this->street = strt;
        this->city = cty;
        this->pin = pn;
    }

    void setBuilding(string bldg)
    {
        this->building = bldg;
    }

    string getBuilding()
    {
        return this->building;
    }

    void setStreet(string strt)
    {
        this->street = strt;
    }

    string getStreet()
    {
        return this->street;
    }

    void setCity(string cty)
    {
        this->city = cty;
    }

    string getCity()
    {
        return this->city;
    }

    void setPin(int pn)
    {
        this->pin = pn;
    }

    int getPin()
    {
        return this->pin;
    }

    void acceptAddress()
    {
        cout << "\nEnter the building name: ";
        cin >> building;

        cout << "\nEnter the street name: ";
        cin >> street;

        cout << "\nEnter the city name: ";
        cin >> city;

        cout << "\nEnter the pincode: ";
        cin >> pin;
    }

    void displayAddress()
    {
        cout<<"\n--------------------------------------------------";
        cout << "\nBuilding: " << building;
        cout << "\nStreet: " << street;
        cout << "\nCity: " << city;
        cout << "\nPincode: " << pin;
        cout<<"\n--------------------------------------------------";
    }
};

int main()
{
    Address a1;
    a1.displayAddress();

    Address a2;
    a2.acceptAddress();
    a2.displayAddress();

    Address a3("Deccan", "FC Road", "Pune", 411038);
    a3.displayAddress();

    Address a4;
    a4.setBuilding("Abil House");
    a4.setStreet("Tilak Road");
    a4.setCity("Pune");
    a4.setPin(411030);

    cout<<"\n"<<a4.getBuilding();
    cout<<"\n"<<a4.getStreet();
    cout<<"\n"<<a4.getCity();
    cout<<"\n"<<a4.getPin();
    return 0;
}