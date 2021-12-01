#include <stdio.h>

// Isaiah Ogbulu, 2/8/2019, Lab 4, Creating a calculator, now with functions WOWIE!

int main(){

int modAns, intEnter1, intEnter2, i, isPrime, powI, factI, sumPow, factAns, input, primeRemainder, fibI, printI;
float addSum, sumAdd, diffSub, multiAns, divAns, floatEnter1, floatEnter2;	//declaring needed variables


float addFunc(float firstAdd, float secondAdd){		//creating function for adding 2 numbers
	sumAdd = firstAdd + secondAdd;
	return sumAdd;
}

float subFunc(float firstSub, float secondSub){		//creating function for subtracting 2 numbers
	diffSub = firstSub - secondSub;
	return diffSub;
}

float multiFunc(float firstMulti, float secondMulti){		//creating function for subtracting 2 numbers
	multiAns = firstMulti * secondMulti;
	return multiAns;
}

float divFunc(float firstDiv, float secondDiv){		//creating function for dividing 2 numbers
	divAns = firstDiv / secondDiv;
	return divAns;
}

int modFunc(int firstMod, int secondMod){		//creating function do get the remainder of the division of 2 numbers
	modAns = firstMod % secondMod;
	return modAns;
}

int primeFunc(int testPrime){		//creating function to test if number is prime
	isPrime = 1;
	for(i = 2;i<testPrime;i++){
        	primeRemainder = testPrime % i;
				
			if(primeRemainder == 0){
				isPrime = 0;
			}
        }

	return isPrime;
}

int factFunc(int testFact){		//creating function for getting the factorial of a number
	factAns = testFact;
	for(factI = testFact - 1; factI > 1; factI--){
		factAns *= factI;
	}

	return factAns;
}

float powFunc(float firstPow, float secondPow){		//creating function for multiplying a number by a given power
	sumPow = firstPow;
	for(powI = 1; powI< secondPow; powI++){
		sumPow  *= firstPow;
	}
	return sumPow;
}

int fibFunc(int numFibs){		//creating number for outputting fibbonacci sequence (diddn't have time to finish D:)
int fibArray[numFibs];
for(fibI = 0; fibI < numFibs; fibI++)
	fibArray[fibI] = 1;
	return numFibs;
}

do{
	printf("Enter the number of the type of calculation that you want to preform");		//displaying menu for input
	
	printf("\n(1)Addition\n(2)Subtraction\n(3)Multiplication\n(4)Division\n");
	printf("(5)Modulus (Integers Only)\n(6)Test if prime (Integers only)\n(7)Factorial(Integers only)\n(8)Power\n(9)Fibonacci Sequence\n(0)Exit\n");
	scanf("%d", &input);
	
	switch(input){
		case 0:
			printf("Exiting Program");		//exiting program
			break;
		
		case 1:
			printf("Enter the first number you want to add\t");		//propting users for numbers to add
			scanf("%f", &floatEnter1);	
			printf("Enter the second number you want to add\t");
			scanf("%f", &floatEnter2);
			printf("%.2f + %.2f = %.2f\n" ,floatEnter1, floatEnter2, addFunc(floatEnter1,floatEnter2));
			break;
		
		case 2:
			printf("Enter the number you want subtracted\t");
			scanf("%f", &floatEnter1);
			printf("Enter the number you want to subract by\t");
			scanf("%f", &floatEnter2);

			printf("%.2f - %.2f = %.2f\n" ,floatEnter1, floatEnter2,subFunc(floatEnter1,floatEnter2));
			break;
		
		case 3:
			printf("Enter the number you want mulitply\t");
			scanf("%f", &floatEnter1);
			printf("Enter the numbeer you want to multiply by\t");
			scanf("%f", &floatEnter2);

			printf("%.2f * %.2f = %.2f\n" ,floatEnter1, floatEnter2,multiFunc(floatEnter1,floatEnter2));
			break;
		
		case 4:
			printf("Enter the number you want to be divided\t");
			scanf("%f", &floatEnter1);
			printf("Enter the number you want to divide by\t");
			scanf("%f", &floatEnter2);

			printf("%.2f / %.2f = %.2f\n" ,floatEnter1, floatEnter2,divFunc(floatEnter1,floatEnter2));
			break;
			
		case 5:
			printf("Enter the number you want to get the remainder of\t");
			scanf("%d", &intEnter1);
			printf("Enter the number you want to devide by\t");
			scanf("%d", &intEnter2);

			printf("%5d / %5d has %5d remainder\n" ,intEnter1, intEnter2,modFunc(intEnter1,intEnter2));
			break;
			
		case 6:
			printf("Enter the number you want to test\t");
			scanf("%d", &intEnter1);

			isPrime = primeFunc(intEnter1);

       		if(isPrime == 0){
				printf("%d is not prime \n", intEnter1);
			}
			else{
				printf("%d is prime\n", intEnter1);
			}
			break;
		
		case 7:
			printf("Enter the number you want to get the factorial of\t");
			scanf("%d", &intEnter1);

			printf("%5d! = %5d\n" ,intEnter1 ,factFunc(intEnter1));
			break;
			
		case 8:
			printf("Enter the first number\t");
			scanf("%f", &floatEnter1);
			printf("Enter the second number\t");
			scanf("%f", &floatEnter2);

			printf("%.2f ^%.2f = %.2f\n" ,floatEnter1, floatEnter2,powFunc(floatEnter1,floatEnter2));
			break;
			
		case 9:
			printf("Enter the number of how much of the sequence you want to see\t");
			scanf("%d", &intEnter1);

			for(printI = 0; printI < intEnter1; printI++){
				printf("");
			}
			break;

		default:
			printf("Number Entered not within expected values, please enter agian");
			break;
	}
	
}while(input != 0);


}

