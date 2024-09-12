#include <iostream>
using namespace std;

class Stack
{
    int size;
    int top;
    int *stk;

public:
    Stack(int n)
    {
        this->size = n;
        this->top = -1;
        stk = new int[5];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == size - 1)
            return true;
        else
            return false;
    }

    bool stackPush(int a)
    {
        if (isFull())
            return false;
        else
        {
            stk[++top] = a;
            return true;
        }
    }

    bool isPop(int &x)
    {
        if (isEmpty())
            return false;
        else
        {
            x = stk[top--];
            return true;
        }
    }

    bool stackPeek(int &a)
    {
        if (isEmpty())
            return false;
        else
        {
            a = stk[top];
            return true;
        }
    }

    bool display()
    {
        if (isEmpty())
            return false;
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout<<stk[i]<<"\t";
            }
            return true;
        }
    }
};

int menuChoice()
{
    int mChoice;
    cout<<"\n\n****Menu****";
    cout<<"\n1. Push Element";
    cout<<"\n2. Pop Element";
    cout<<"\n3. Peek Element";
    cout<<"\n4. Display";
    cout<<"\n\nEnter your choice: ";
    cin>>mChoice;
    return mChoice;
}

int main()
{
    int n, choice;
    cout<<"\nEnter the size of Stack: ";
    cin>>n;

    Stack s(n);

    while((choice = menuChoice()) != 0)
    {
        switch(choice)
        {
            case 1:
                {
                    int k;
                    cout<<"\nEnter the element you want to push: ";
                    cin>>k;

                    if(s.stackPush(k))
                        cout<<"\n"<<k<<" is added successfully.";
                    else  
                        cout<<"\nSTACK OVERFLOW";    
                }
                break;
            
            case 2:
                {
                    int x;
                    if(s.isPop(x))
                        cout<<"\n"<<x<<" is popped successfully";
                    else
                        cout<<"\nSTACK UNDERFLOW";    
                }
                break;
            
            case 3:
                {
                    int x;
                    if(s.stackPeek(x))
                        cout<<"\n"<<x<<" is the top element.\n";
                    else
                        cout<<"\nStack is empty";    
                }
                break;
            
            case 4:
                {
                    if(s.display());
                    else
                        cout<<"\nStack is empty";
                }
                break;

            default:
                cout<<"\nInvalid Choice !!!!";    
        }
    }

}