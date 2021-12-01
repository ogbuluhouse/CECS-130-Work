#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Isaiah Ogbulu, 2/15/2019, Lab 5, Creating an everchanging story with the use of arrays

int main(){

char userCar[20],  userName[20], userColor[20], userAge[20], userSeason[20], printSeason[20], *printThing;      //declaring needed variables
int input, randPlaceNum, randThingNum, randCollectNum, randFoodNum;
srand(time(NULL));          //randomizing the randomizer seed


char *randPlace[] = {"in your ear","under your hat","up your nose"};        //creating arrays of words and phrase for randomization
char *randThing[] = {"cat","flash drive","phone"};
char *randCollect[] = {"model trains","pes despensers","action figures","wax figures of bob ross","bionicles"};
char *randFood[] = {"only the crust of pb&j sandwitches","some stuff that tastes like sour skittles but looks like gritz","moldy bread","stale cherios"};

do{

    printf("What is your name?\t");         //Prompting user to enter details for stories
    scanf("%s", &userName);

    printf("What is your dream car?\t");
    scanf("%s", &userCar);

    printf("What is your favorite color?\t");
    scanf("%s", &userColor);

    printf("How old are you?\t");
    scanf("%s", &userAge);

    printf("What is your favorite season?\t");
    scanf("%s", &userSeason);

    randPlaceNum = rand()%3;            //getting random numbers for each array
    randThingNum = rand() %4;
    randCollectNum = rand()%5;
    randFoodNum = rand()%4;

    printThing = randThing[randThingNum];   //declring set string so it doesn't change from each reference


    printf("\nYou are walking down the street when a %s %s rolles up.\n\n", userColor, userCar);            //Outputting my Epic Tale
    printf("A woman peaks out through a crack in the window, You wouldn't happen to be %s would you?\n\n", userName);
    printf("Yes! you answer wondering where this is going.\n\n");
    printf("She says Perfect! we heard you just turned %s and we wanted to give you a chance to get a nice prize!\n\n", userAge);
    printf("All you need to do is hide this %s from the cops until we come back and get it and you can keep this car.\n\n", printThing);
    printf("hhmmmm you say, that doesn't sound like too good of a deal to me i don't know why the police want that %s.\n\n", printThing);
    printf("Well only since we're in a bind right now we will fill the trunk with as much money that will fit.\n\n");
    printf("Alright I'll do it!, you declare, now hand me that %s already I'm already drooling about all the %s I'm going to buy.\n\n", printThing, randCollect[randCollectNum]);
    printf("She hands you the and speeds off, at the same time cops come from the way she came.\n\n");
    printf("They grab you and throw you in a metal box for months and feeding you only %s, interrogating you everyday for the location of the %s.\n\n", randFood[randFoodNum], printThing);
    printf("They finally give up and take you to an uknown place and push out of a van remarking, we will be watching, before speeding off.\n\n");
    printf("You were in there so long it was %s when you left, your favorite season\n\n", userSeason);
    printf("But that doesn't matter what matters is that you still have have the %s, which you pull out\n\n", printThing);
    printf("It was %s the whole time\n\n", randPlace[randPlaceNum]);

    printf("Enter 0 to exit, and 1 to hear another story");     //prompitng the user if they want to see another story
    scanf("%d", &input);
}while(input != 0);

}


