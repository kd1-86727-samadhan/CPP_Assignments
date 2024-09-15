#include <iostream>
using namespace std;
#define size 5
typedef enum
{
    EXIT,
    ACCEPT,
    PRINT,
    SEARCH,
    PERCENTAGE
} menu;

class Student
{
    const int rollNumber;
    string sname;
    char gender;
    int marks[3];
    static int generate_rollNo;

public:
    Student() : rollNumber(++generate_rollNo)
    {
        this->sname = "\"\"";
        this->gender = 'M';
    }

    Student(string nm, char gen) : rollNumber(++generate_rollNo)
    {
        this->sname = nm;
        this->gender = gen;
    }

    int getRollNo()
    {
        return this->rollNumber;
    }

    void accept()
    {
        cout << "\nEnter the name: ";
        cin >> sname;

        cout << "\nEnter the gender(M/F): ";
        cin >> gender;

        cout << "\nEnter the marks of 3 subject: ";
        for (int i = 0; i < 3; i++)
        {
            cout << "\nMarks of subject-" << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void percentage()
    {
        float totalMarks = 0.0, per;
        for (int i = 0; i < 3; i++)
        {
            totalMarks = totalMarks + marks[i];
        }
        per = totalMarks / 3;
        cout <<"\t\t"<<per << "\n";
    }

    void display()
    {
        cout<<"\n----------------------------------------------------------------";
        cout<<"\n"<<rollNumber<<"\t\t"<<sname<<"\t\t"<<gender;
    }
}; // Student

int Student::generate_rollNo = 100;

int search(Student **sarr)
{
    int rollno;
    cout << "\nEnter the roll number you want to search: ";
    cin >> rollno;

    for (int i = 0; i < size; i++)
    {
        if (rollno == sarr[i]->getRollNo())
        {
            return i;
        }
    }
    return -1;
}

menu menuChoice()
{
    int mChoice;
    cout << "\n\n****Menu****";
    cout << "\n1. Accept";
    cout << "\n2. Print";
    cout << "\n3. Search";
    cout << "\n4. Percentage";
    cout << "\n\nEnter your choice: ";
    cin >> mChoice;
    return (menu)mChoice;
}

int main()
{
    Student *sarr[5];

    int choice, rollNo;

    for (int i = 0; i < size; i++)
    {
        sarr[i] = new Student();
    }

    while ((choice = menuChoice()) != 0)
    {
        switch (choice)
        {
            case EXIT:
            {
                cout << "\nEnd of program";
            }
            break;
            
            case ACCEPT:
            {
                for (int i = 0; i < size; i++)
                {
                    sarr[i]->accept();
                }
            }
            break;

            case PRINT:
            {
                cout<<"\n----------------------------------------------------------------";
                cout<<"\nRoll Number\tName\t\tGender";
                for (int i = 0; i < size; i++)
                {
                    sarr[i]->display();
                }
                cout<<"\n----------------------------------------------------------------";
            }
            break;

            case SEARCH:
            {
                int index;
                index = search(sarr);
                if (index == -1)
                    cout << "\nRoll number is not found.";
                else
                    cout << "\n"<< sarr[index]->getRollNo() << " found at index-" << index;
            }
            break;

            case PERCENTAGE:
            {
                cout<<"\n----------------------------------------------------------------";
                cout<<"\nRoll Number\tName\t\tGender\t\tPercentage";
                for (int i = 0; i < size; i++)
                {
                    sarr[i]->display();
                    sarr[i]->percentage();
                }
                cout<<"\n----------------------------------------------------------------";
            }
            break;

            default:
                cout << "\nInvalid choice";
        } // switch
    }   // while
}