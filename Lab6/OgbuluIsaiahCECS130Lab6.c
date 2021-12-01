#include <stdio.h>
#include <stdlib.h>

// Isaiah Ogbulu, 3/1/2019, Lab 6, Creating a phonebook with structures

typedef struct phoneStruct{
    char *fName;
    char *lName;
    char *pNumber;
}phoneBook;

int main(){

phoneBook *bookArray;
int input, i, u;
int arraySize = 0;
char inFirst[20],inLast[20],inNum[20]; 

do{
    printf("Phone Book Application\n0) End the program\n1) Add Friend\n2) Delete Friend\n3) Show Phone Book\n");        
    printf("What do you want to do?\t");                      //Prompts the user for input and assigns it to a variable
    scanf("%d",&input);

    switch(input){
        case 0:                 //exits program if user enters 0
            printf("Exiting Program...");
        break;

        case 1:                         //If the user enters 1 they're prompted to for a new friend then it's recorded to new allocated space
            printf("First Name: ");
            scanf("%s", inFirst);
            printf("Last Name: ");
            scanf("%s", inLast);
            printf("Phone Number: ");
            scanf("%s", inNum);

            bookArray = malloc(sizeof(char[20]));

            bookArray[arraySize].fName = inFirst;
            bookArray[arraySize].lName = inLast;
            bookArray[arraySize].pNumber = inNum;
            arraySize++;
            free(bookArray);
        break;

        case 2:                 //If the user enters 2 they're poromted for a name that is compaired to existing contacts then made null if matched
            printf("First Name: ");
            scanf("%s", inFirst);
            printf("Last Name: ");
            scanf("%s", inLast);

            for(u = 0;u < sizeof(bookArray);u++){
                if(stricmp(inFirst, bookArray[u].fName) == 0 && stricmp(inLast, bookArray[u].lName) == 0){
                    bookArray[u].fName = NULL;
                    bookArray[u].lName = NULL;
                    bookArray[u].pNumber = NULL;
                }
            }
            arraySize--;
        break;

        case 3:                             //if the user enters 3 this prints out each element in the struct array
            printf("Phone book entries:\n");

            for(i = 0;i < sizeof(bookArray);i++){
                if(bookArray[i].fName != NULL){
                    printf("%s\t%s\t%s\n", bookArray[i].fName, bookArray[i].lName, bookArray[i].pNumber);
                }
            }

        break;

        default:
            printf("Unexpected Value please choose a number from 0 to 3.");
        break;
    }
}while(input != 0);         //exit statement for while loop

}
