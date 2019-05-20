#include <stdio.h>
#include <string.h>

#include "phone.h"

#define MAX 50

extern char password[];
extern int rmBuffer;
extern int userNo;

void registerPhoneData()
{
    struct Contact *pPhoneBook;
    pPhoneBook = &PhoneBook;
    static int count_service = 0;
    char Inpassword[13];
    int passwordmark = 0;

    printf("\nAsk to type password\n");

    if(count_service == 3)
    {
        printf("\n>>Not matched(3times)!!!\n >>You are not allowed to access PhoneBook.\n");
    }
    else {
        do{
            printf("Password: ");
            scanf("%12s", Inpassword);
            while((rmBuffer = getchar()) != '\n' && rmBuffer != EOF);

            if((strcmp(Inpassword, password)) == 0)
            {
                count_service = 0;
                printf("New User Name: ");
                scanf("%9s", (pPhoneBook+userNo)->Name); while((rmBuffer = getchar()) != '\n' && rmBuffer != EOF);
                printf("PhoneNumber: ");
                scanf("%14s", (pPhoneBook+userNo)->PhoneNumber); while((rmBuffer= getchar()) != '\n' && rmBuffer != EOF);
                printf("Registered...\n");

                userNo++;
                passwordmark = 1;
            } else {
                if (count_service == 2)
                {
                    printf("\n>>Not matched(3times)!!!\n >>You are not allowed to access PhoneBook.\n"); break;
                }
                else if (count_service ==1) {
                	printf("\n>>Not matched(twice)!!!\n");
            	}
            	else if (count_service ==0) {
            		printf("\n>>Not matched!!!\n");
				}
				count_service++;
            }
        }while (passwordmark != 1);
    }
}
