
#include <stdio.h>

// Isaiah Ogbulu, 1/30/2019, Lab 3,Creating a calculator good enought to rival the enigma in computing prowess 

int main(){

int input = 0;			//declaring needed integer variables
int firstMod = 0;
int secondMod = 0;
int testPrime = 0;
int primeRemainder = 0;
int i = 2;
int count = 0;
int isPrime = 0;

float firstAdd = 0.0;		//declaring needed float varianbles
float secondAdd = 0.0;
float firstSub = 0.0;
float secondSub = 0.0;
float firstMultiply = 0.0;
float secondMultiply = 0.0;
float firstDivide = 0.0;
float secondDivide = 0.0;


do{
	printf("Enter the number of the type of calculation that you want to preform");	//outputing header

	printf("\n(1)Addition\n(2)Subtraction\n(3)Multiplication\n(4)Division\n(5)Modulus (Integers Only)\n(6)Test if prime (Integers only)\n(7)Exit\n");
	scanf("%d", &input);		//outputing options and assinging input to integer
	
    switch(input){		//initializing switch that evaluates user input
        case 1:
            printf("Enter First number:\t");	//adding numbers entered by user input
            scanf("%f", &firstAdd);
            printf("Enter Second number:\t");
            scanf("%f", &secondAdd);
            
            printf("%5.2f + %5.2f = %5.2f\n", firstAdd, secondAdd, firstAdd + secondAdd);
            break;
        case 2:
            printf("Enter First number:\t");		//subtracting numbers based off user input
            scanf("%f", &firstSub);
            printf("Enter Second number:\t");
            scanf("%f", &secondSub);
            
            printf("%5.2f - %5.2f = %5.2f\n", firstSub, secondAdd, firstSub - secondSub);
            break;
        case 3:
            printf("Enter First number:\t");		//multiplying numbers based off user input
            scanf("%f", &firstMultiply);
            printf("Enter Second number:\t");
            scanf("%f", &secondMultiply);
            
            printf("%5.2f * %5.2f = %5.2f\n", firstMultiply, secondMultiply, firstMultiply * secondMultiply);
            break;
        case 4:
            printf("Enter First number:\t");		//deviding numbers based off user input
            scanf("%f", &firstDivide);
            printf("Enter Second number:\t");
            scanf("%f", &secondDivide);
            
            printf("%5.2f / %5.2f = %5.2f\n", firstDivide, secondDivide, firstDivide / secondDivide);
            break;
        case 5:
			printf("Enter First number:\t");		//Getting the remainder of given numbers
            scanf("%d", &firstMod);
            printf("Enter Second number:\t");
            scanf("%d", &secondMod);
            
            printf("%3d / %3d has %3d remainder\n", firstMod, secondMod, firstMod % secondMod);
            break;
        case 6:
        	printf("Enter the number you want to test:\t");		//Taking user input then deviding the number by every number between it and 2 to test if any give a remainder
        	scanf("%d", &testPrime);
        	
        	for(i = 2;i<testPrime;i++){
        		primeRemainder = testPrime % i;
				
				if(primeRemainder == 0){
					isPrime = 1;
					count = i;
				}
        	}
        	if(isPrime == 1){
				printf("%d is not prime: %d * %d = %d\n", testPrime, count, testPrime/count, testPrime);
			}
			else{
				printf("%d is prime\n", testPrime);
			}
        	
            break;
        case 7:								//exiting program if selected
        	printf("Exiting Program");
            break;
        default:					//outputing error if number doesn't fit switch
            printf("Number not within expected values, please enter number again\n");
            break;
}
}while(input != 7);

}
