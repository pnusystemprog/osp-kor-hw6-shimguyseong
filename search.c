#include <stdio.h>
#include <string.h>

#include "phone.h"

#define MAX 50

extern int rmBuffer;
extern int userNo;

void searchByName()
{
    struct Contact *pPhoneBook;
    pPhoneBook = &PhoneBook;
    char searchName[10];

    printf("\nEnter a name to search: ");
    scanf("%9s", searchName); while((rmBuffer= getchar()) != '\n' && rmBuffer != EOF);

    for(int i = 0; i < userNo; i++)
    {
        if (strcmp((pPhoneBook+i)->Name, searchName) == 0)
        {
            printf("\n%s  %s\n", (pPhoneBook+i)->Name, (pPhoneBook+i)->PhoneNumber);
            break;
        }

    }
}

void printAll()
{
    struct Contact *pPhoneBook;
    pPhoneBook = &PhoneBook;

    printf("\n<<Display all contacts in the PhoneBook>>\n");
    for(int i = 0; i < userNo; i++)
    {
        printf("%s  %s\n", (pPhoneBook+i)->Name, (pPhoneBook+i)->PhoneNumber);
    }
}
