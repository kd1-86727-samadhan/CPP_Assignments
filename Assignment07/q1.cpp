#include <iostream>
using namespace std;

class Product
{
    int id;
    string title;
    double price;

public:
    Product()
    {
        this->id = 0;
        this->title = "\"\"";
        this->price = 0;
    }

    Product(int id, string tittle, double price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return this->id;
    }

    void setTitle(string title)
    {
        this->title = title;
    }

    string getTitle()
    {
        return this->title;
    }

    void setPrice(double price)
    {
        this->price = price;
    }

    int getPrice()
    {
        return this->price;
    }

    virtual void accept()
    {
        cout << "\nEnter the id: ";
        cin >> this->id;

        cout << "\nEnter the title: ";
        cin >> this->title;

        cout << "\nEnter the price: ";
        cin >> this->price;
    }

    virtual void display()
    {
        cout<<"\nId\t\tTitle\t\tPrice";
        cout<<"\n"<<this->id<<"\t"<<this->title<<"\t"<<this->title;    
        // cout << "\nId: " << this->id;
        // cout << "\nTitle: " << this->title;
        // cout << "\nPrice: " << this->price;
    }
}; // Product

class Book : public Product
{
    string author;

protected:
    void acceptBook()
    {
        cout << "\nEnter the author name: ";
        cin >> this->author;
    }

    void displayBook()
    {
        // cout << "\nAuthor: " << author;
        cout<<"\nAuthor";
        cout<<this->author;
    }

public:
    Book()
    {
        cout << "\nBook()";
        this->author = "\"\"";
    }

    Book(int id, string title, string author, double price) : Product(id, title, price)
    {
        this->author = author;
    }

    void setAuthor(string author)
    {
        this->author = author;
    }

    string getAuthor()
    {
        return this->author;
    }

    void accept()
    {
        Product::accept();
        acceptBook();
    }

    void display()
    {
        Product::display();
        displayBook();
    }
}; // Book

class Tape : public Product
{
    string artist;

protected:
    void acceptTape()
    {
        cout << "\nEnter the artist name: ";
        cin >> this->artist;
    }

    void displayTape()
    {
        // cout << "\nArtist name: " << artist;
        cout << "\nArtist"; 
        cout<< artist;
    }

public:
    void setArtist(string artist)
    {
        this->artist = artist;
    }

    string getArtist()
    {
        return this->artist;
    }

    void accept()
    {
        Product::accept();
        acceptTape();
    }

    void display()
    {
        Product::display();
        displayTape();
    }
}; // Tape

void findBill(Product **arr, int index)
{
    double discountPrice = 0.0;
    double finalPrice = 0.0;
    for(int i = 0; i < index; i++)
    {
        if(typeid(*arr[i]) == typeid(Book))
        {
            discountPrice = arr[i]->getPrice() - (arr[i]->getPrice() * 0.10);
        }
        else
            discountPrice = arr[i]->getPrice() - (arr[i]->getPrice() * 0.05);
        {

        }
        finalPrice = finalPrice + discountPrice;
    }
    cout<<"\nFinal Bill: "<<finalPrice;
}
enum EMenu
{
    EXIT,
    ADD_BOOK,
    ADD_TAPE,
    DISPLAY_BOOK,
    DISPLAY_TAPE,
    FINAL_BILL
};  

int menuChoice()
{
    cout<<"\n****************************************";
    int mChoice;
    cout << "\n0. Exit:";
    cout << "\n1. Add Book";
    cout << "\n2. Add Tape:";
    cout << "\n3. Display Book";
    cout << "\n4. Display Tape";
    cout << "\n5. Final Bill";
    cout<<"\n****************************************";
    cout << "\n\nEnter your choice: ";
    cin >> mChoice;
    return mChoice;
}

int main()
{
    Product *arr[3];
    int index = 0;
    int choice, i;

    while((choice = menuChoice()) != 0)
    {
        switch(choice)
        {
            case ADD_BOOK:
                {
                     if(index < 3)
                     {
                        arr[index] = new Book;
                        arr[index]->accept();
                        index++;
                     }   
                     else
                     {
                        cout<<"\nArray is full....";
                     }
                }
                break;

            case ADD_TAPE:
                {
                    if(index < 3)
                    {
                        arr[index] = new Tape;
                        arr[index]->accept();
                        index++;
                    }
                    else
                    {
                        cout<<"\nArray is full....";
                    }
                    
                }
                break;

            case DISPLAY_BOOK:
                {
                    for(i = 0; i < index; i++)
                    {
                        if(typeid(*arr[i]) == typeid(Book))
                        {
                            arr[i]->display();
                        }
                    }
                }
                break;

            case DISPLAY_TAPE:
                {
                    for(i = 0; i < index; i++)
                    {
                        if(typeid(*arr[i]) == typeid(Tape))
                        {
                            arr[i]->display();
                        }
                    }
                }
                break;
            
            case FINAL_BILL:
                {
                    findBill(arr, index);
                }
                break;

            default:
                cout<<"\nInvalid choice !!!!";
                break;
        }   // switch

    }   // while

    for(i = 0; i < index; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }

    // delete arr;
    // arr[] = NULL;
    return 0;
}
