#include <iostream>
using namespace std;

class Volume
{
    int length;
    int width;
    int height;

public:
    Volume()
    {
        cout << "\nInside Default/Parameterless Constructor Called.";
        this->length = 2;
        this->width = 3;
        this->height = 4;
    }

    // Volume(int value) : length(value), width(value), height(value){}
    Volume(int value)
    {
        this->length = value;
        this->width = value;
        this->height = value;
    }

    Volume(int l, int b, int h)
    {
        cout << "\nInside Parameterized Constructor Called.";
        this->length = l;
        this->width = b;
        this->height = h;
    }

    void acceptVolume()
    {
        cout << "\nEnter the value of length: ";
        cin >> this->length;

        cout << "\nEnter the value of breadth: ";
        cin >> this->width;

        cout << "\nEnter the value of height: ";
        cin >> this->height;
    }

    void displayVolume()
    {
        cout << "\nLength: " << this->length;
        cout << "\nBreadth: " << this->width;
        cout << "\nHeight: " << this->height;
    }

    void calculateVolume()
    {
        cout<<"\nLength: "<<this->length;
        cout<<"\nBreadth: "<<this->width;
        cout<<"\nHeight: "<<this->height;
        cout<<"\nVolume = "<<this->length * this->width * this->height;
    }
};

int menuChoice()
{
    int choice;
    cout << "\n\n****Menu****";
    cout << "\n1. Calculate volume with default values";
    cout << "\n2. Calculate volume with length, breadth, height";
    cout << "\n3. Calculate volume with different length, breadth, height";
    cout << "\nEnter your choice: ";
    cin >> choice;
    return choice;
}



int main()
{
    Volume v1;
    int choice;


    while ((choice = menuChoice())!= 0)
    {
        switch(choice)
        {       
            case 1:
                {
                    v1.calculateVolume();
                }
                break;
            
            case 2:
                {
                    Volume v2(4);
                    v2.calculateVolume();
                }
                break;
            
            case 3:
                {
                    Volume v3(4, 5, 6);
                    v3.calculateVolume();
                }
                break;

            default:
                cout<<"\nInvalid choice";
                break;
        } // switch
    } // while
    return 0;
}
