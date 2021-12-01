#include <stdio.h>
#include <stdlib.h>

// Isaiah Ogbulu, 3/8/2019, Lab 7, Adding funtionality to phonebook

typedef struct phoneStruct{
    char fName[20];
    char lName[20];
    char pNumber[20];
}phoneBook;

int main(){

phoneBook *bookArray;			//initializing  struct array and allocating memory for it
int input, i, u, randNum;			//declaring needed bariables
int bookSize = 0;
char inFirst[20],inLast[20],inNum[20]; 
srand(time(NULL));		//randomizing number generation

do{				//prompting user for unput and recording it
    printf("\nPhone Book Application\n0) End the program\n1) Add Friend\n2) Delete Friend\n3) Show Phone Book\n4 Sort list by First Name\n5) Find a phone Number\n6) Randomly Select friend\n7) Delete Phone Book");        
    printf("\nWhat do you want to do?\t");                      
    scanf("%d",&input);
		
    switch(input){
        case 0:                 
            printf("\nExiting Program...");
        break;

        case 1:              //allocates new memory and assings user unputs to array indexes            
            

			if(bookSize < 1){
				bookArray = (phoneBook *) malloc(sizeof(phoneBook)*1);
			}
			else{
				bookArray = (phoneBook *) realloc(bookArray,(bookSize + 1) * sizeof(phoneBook));
			}
            
            printf("First Name: ");
            scanf("%s", inFirst);
            printf("Last Name: ");
            scanf("%s", inLast);
            printf("Phone Number: ");
            scanf("%s", inNum);

            strcpy(bookArray[bookSize].fName,inFirst);
            strcpy(bookArray[bookSize].lName,inLast);
            strcpy(bookArray[bookSize].pNumber,inNum);
        	bookSize++;
        	printf("%d", bookSize);
        	
        break;
        case 2:            //compares given name with struct array and deletes if it's a match
     
            printf("First Name: ");
            scanf("%s", inFirst);
            printf("Last Name: ");
            scanf("%s", inLast);

            for(u = 0;u < sizeof(bookArray);u++){
                if(stricmp(inFirst, bookArray[u].fName) == 0 && stricmp(inLast, bookArray[u].lName) == 0){
                    bookArray[u].fName = "";
                    bookArray[u].lName = "";
                    bookArray[u].pNumber = "";
                    printf("\nFile Deleted");
                }else{
                	printf("\nFile not found");
				}	
            }
            bookSize--;
        break;

        case 3:						//ouputs all elements in struct array                             
            printf("Phone book entries:\n");

            for(i = 0;i < bookSize;i++){
                if(bookArray[i].fName != NULL){
                    printf("%s\t%s\t%s\n", bookArray[i].fName, bookArray[i].lName, bookArray[i].pNumber);
                }
            }

        break;

        case 4:		//This is where my sort function should be
			
        break;

        case 5:		//WHen the user enters 5, I prompt for a name and then return the phone number associated withit
        	printf("First Name: ");
            scanf("%s", inFirst);
            printf("Last Name: ");
            scanf("%s", inLast);
        	
			for(u = 0;u < sizeof(bookArray);u++){
                if(stricmp(inFirst, bookArray[u].fName) == 0 && stricmp(inLast, bookArray[u].lName) == 0){
                    printf("\nPhone Number is %s", bookArray[u].pNumber);
                }else{
                	printf("\nPerson not found");
				}	
            }
        break;

        case 6:		//generates random number and returns number to call based off generation
			randNum = rand()%bookSize;
			printf("\nCall the number %s", bookArray[randNum].pNumber);
        break;

        case 7:			//deletes all contacts and resets variable for array size
			for(u = 0;u < bookSize;u++){
                    bookArray[u].fName = "";
                    bookArray[u].lName = "";
                    bookArray[u].pNumber = "";
            }
            bookSize = 0;
			printf("Contacts Deleted");
        break;

        default:
            printf("Unexpected Value please choose a number from 0 to 7.");
        break;
    }
}while(input != 0);         //exit statement for while loop

free(bookArray);			//frees memory
}
