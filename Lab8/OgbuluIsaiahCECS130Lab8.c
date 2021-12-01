#include <stdio.h>
#include <stdlib.h>

// Isaiah Ogbulu, 3/22/2019, Lab 8, Inputting and outputting to files

typedef struct phoneStruct{
    char fName[20];
    char lName[20];
    char pNumber[20];
}phoneBook;

int main(){

phoneBook *bookArray;			//initializing  struct array and allocating memory for it
int input, i, u, randNum, count = 0;			//declaring needed bariables
int bookSize = 0;
char inFirst[20],inLast[20],inNum[20], pathName[30], fileName[30], pathCombine[60]; 
srand(time(NULL));		//randomizing number generation
FILE *filePoint;

do{				//prompting user for unput and recording it
    printf("\nPhone Book Application\n0) End the program\n1) Add Friend\n2) Delete Friend\n3) Show Phone Book\n4 Sort list by First Name\n5) Find a phone Number");
    printf("\n6) Randomly Select friend\n7) Delete Phone Book\n8) Save your contacts to a file\n9) Read your cantacts from a file");        
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
            scanf("%s", &bookArray[bookSize].fName);
            printf("Last Name: ");
            scanf("%s", &bookArray[bookSize].lName);
            printf("Phone Number: ");
            scanf("%s", &bookArray[bookSize].pNumber);

        	bookSize++;
        	printf("%d", bookSize);
        	
        break;
        case 2:            //compares given name with struct array and deletes if it's a match, I broke It along the way and I don't know how
     
            printf("First Name: ");
            scanf("%s", inFirst);
            printf("Last Name: ");
            scanf("%s", inLast);

            for(u = 0;u < sizeof(bookArray);u++){
                if(stricmp(inFirst, bookArray[u].fName) == 0 && stricmp(inLast, bookArray[u].lName) == 0){
                    //bookArray[u].fName = "";
                    //bookArray[u].lName = "";
                    //bookArray[u].pNumber = "";
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

        case 7:			//deletes all contacts and resets variable for array size I also broke this so I commented it out
			for(u = 0;u < bookSize;u++){
                    //bookArray[u].fName = "";
                    //bookArray[u].lName = "";
                    //bookArray[u].pNumber = "";
            }
            bookSize = 0;
			printf("Contacts Deleted");
        break;

        case 8:

            printf("\n1) To enter the path that you want to save your document to\n2) To save it to the default path");     //promting user for path
            scanf("%d", input);

            if(input == 1){
                printf("\nEnter the path that you want to save your document to (Not including the document name)\t");      //prompting user for file name
                scanf("%s", pathName);
            }

            else{
                pathName = "C:\\FileSavedHere\\";           //sets default path
            }

            printf("\nEnter in the name for the file with the extension\t");
            scanf("%s", &fileName);

            strcpy(pathCombine, pathName);
            strcat(pathCombine, fileName);           

            filePoint = fopen(pathCombine, "w+");           //combines given name and path then outputs file

            for(i = 0;i < bookSize; i++){
                fprintf(filePoint, "%s", &bookArray[i].fName);
                fprintf(filePoint, "%s", &bookArray[i].lName);
                fprintf(filePoint, "%s", &bookArray[i].pNumber);
            }

            fclose(filePoint);
        break;

        case 9:
            printf("\nEnter the path to the document that you want read");      //promts the user for path name
            scanf("%d", pathName);
            
            count = 0;

            filePoint = fopen(pathName, "r");       //opens up file based off given path
            while(scanf("%s", filePoint) == 1){

            bookArray = (phoneBook *) realloc(bookArray,(bookSize + 1) * sizeof(phoneBook));            //while there are still strings to read, allocates space and scans in new elements
            fscanf(filePoint,"%s %s %s", bookArray[bookSize].fName, bookArray[bookSize].lName, bookArray[bookSize].pNumber);

            count++;            
            bookSize++;
            }

            printf("Sucessfully added %d Entries", count);          //outputs how many entries were added to array

            fclose(filePoint);
        break;

        default:
            printf("Unexpected Value please choose a number from 0 to 9.");
        break;
    }
}while(input != 0);         //exit statement for while loop

free(bookArray);			//frees memory
}
