#include<iostream>
using namespace std;

class Time
{
    int hrs;
    int mins;
    int sec;

    public:
        Time()
        {
            hrs = 1;
            mins = 1;
            sec = 1;
        }

        Time(int h, int m, int s)
        {
            hrs = h;
            mins = m;
            sec = s;
        }

        void setHrs(int h)
        {
            this->hrs = h;
        }

        int getHrs()
        {
            return this->hrs;
        }

        void setMins(int m)
        {
            this->mins = m;
        }

        int getMins()
        {
            return this->mins;
        }

        void setSec(int s)
        {
            this->sec = s;
        }

        int getSec()
        {
            return this->sec;
        }

        void acceptTime()
        {
            cout<<"\nEnter the hours: ";
            cin>>hrs;
            
            cout<<"\nEnter the minutes: ";
            cin>>mins;
            
            cout<<"\nEnter the seconds: ";
            cin>>sec;
        }

        void displayTime()
        {
            cout<<"\nTime = "<<hrs<<" : "<<mins<<" : "<<hrs;
        }
};

int main()
{
    Time **ptr = new Time*[2];

    for(int i = 0; i < 5; i++)
    {
        ptr[i] = new Time();
        ptr[i]->acceptTime();
    }

    for(int i = 0; i < 5; i++)
    {
        ptr[i]->displayTime();
    }

    for(int i = 0; i < 5; i++)
    {
        delete ptr[i];
        ptr[i] = NULL;
    }

    delete []ptr;
    ptr = NULL;
}