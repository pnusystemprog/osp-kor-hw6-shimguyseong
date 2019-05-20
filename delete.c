#include <stdio.h>
#include <string.h>

#include "phone.h"

#define MAX 50

extern int rmBuffer;
extern int userNo;

void deleteByName()
{
    struct Contact *pPhoneBook;
    pPhoneBook = &PhoneBook;
    int numtoDelete = 0;
    char enterName[10];

    printf("\nEnter a name to delete: ");
    scanf("%9s", enterName); while((rmBuffer= getchar()) != '\n' && rmBuffer != EOF);

    for(int i = 0; i < userNo; i++){
        if (strcmp((pPhoneBook+i)->Name, enterName) == 0) {
            printf("%s is deleted...", enterName);
            break;
        }
		numtoDelete++;
    }

    for(int i = numtoDelete; i < userNo; i++){
      strcpy((pPhoneBook+i)->Name,((pPhoneBook+i)+1)->Name);

      strcpy((pPhoneBook+i)->PhoneNumber,((pPhoneBook+i)+1)->PhoneNumber);
    }

    userNo--;
}
