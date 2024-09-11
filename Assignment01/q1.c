#include<stdio.h>
typedef enum {EXIT, INITDATE, ACCPETDATE, PRINTDATE} menu;
struct Date
{
    int day;
    int month;
    int year;
};

menu menuChoice()
{
    int choice;
    printf("\n\n****Menu****");
    printf("\n0. Exit");
    printf("\n1. Init Date");
    printf("\n2. Accept Date");
    printf("\n3. Print Date");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void intiDate(struct Date *d1)
{
    d1->day = 1;
    d1->month = 1;
    d1->year = 2004;
}
                
void acceptDate(struct Date *d1)
{
    printf("Enter the day: ");
    scanf("%d", &d1->day);
    
    printf("Enter the month: ");
    scanf("%d", &d1->month);
    
    printf("Enter the year: ");
    scanf("%d", &d1->year);
}

void printDate(struct Date *d1)
{
    printf("\nDate: %d/%d/%d", d1->day, d1->month, d1->year);
}

int main()
{
    struct Date d1;
    int mchoice;
    while((mchoice = menuChoice())!= 0)
    {
        switch(mchoice)
        {
            case EXIT:
            {
                printf("\nExit");
            }
            break;
        
            case INITDATE:
            {
                intiDate(&d1);
                printDate(&d1);
            }
            break;
        
        case ACCPETDATE:
            {
                acceptDate(&d1);
            }
            break;

        case PRINTDATE:
            {
                printDate(&d1);
            }
            break;

        default:
            printf("\nInvalid choice !!!!");
            break;    
        }

    }
    return 0;
}
