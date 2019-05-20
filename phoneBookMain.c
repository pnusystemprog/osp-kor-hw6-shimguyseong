#include <stdio.h>
#include "phone.h"

char password[] = "qwerty1234";

void registerPhoneData();
void printAll();
void searchByName();
void deleteByName();

static int count_service = 0;	// Total number of service requests
int userNo = 0;
int rmBuffer=0;

int main()
{
	int service;		// a variable for storing user's request
	do
	{
        printf("============ Telephone Book Management ============");
        printf("\n <<<1. Register\t 2. Print All \t 3. Search \t 4. Delete \t 5. Exit >>>\n");
        printf(" Please enter your service number (1-5)> ");
		scanf("%d", &service);

		switch(service)
		{
			case 1: registerPhoneData(); break;	// invoke find_ID
			case 2: printAll(); break;
            case 3: searchByName(); break;
            case 4: deleteByName(); break;
		}
	} while (service != 5);	// if Exit is not entered, the loop continues
	return 0;
}

