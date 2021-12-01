#include <stdio.h>

// Isaiah Ogbulu, 1/22/2019, Lab 3, Outputting the a given number converted to different currencies

int main(){

const float UsdToAud = 1.39;        // Declaring constant variabels for converting usd to other currencies
const float UsdToCad = 1.33;
const float UsdToEur = 0.88;
const float UsdToGbp = 0.78;
const float UsdToRub = 67.02;

float amountAud = 0;            // declaring all needed variables as floats to use decimals
float amountCad = 0;
float amountEur = 0;
float amountGbp = 0;
float amountRub = 0;
float amountUsd = 0;
float userAmount = 0;

printf("How much currency to you want to convert?\n");      //Prompting user for input and recording it
scanf("%f", &userAmount);

float convertAud(float input){          //Function to convert usd to upside down dollars (Australian) 
    amountAud = input * UsdToAud;       //by multiplying given number by constant conversion number
    return amountAud;
}

float convertCad(float input){          //Function to convert usd to canadian money by multiplying given number by constant conversion number
    amountCad = input * UsdToCad;
    return amountCad;
}

float convertEur(float input){          //Function to convert usd to euro by multiplying given number by constant conversion number
    amountEur = input * UsdToEur;
    return amountEur;
}

float convertGbp(float input){          //Function to convert usd to british pound by multiplying given number by constant conversion number
    amountGbp = input * UsdToGbp;
    return amountGbp;
}

float convertRub(float input){          //Function to convert usd to Russian Rubles by multiplying given number by constant converson number
    amountRub = input * UsdToRub;
    return amountRub;
}


printf("\tAUD|\tCAD|\tEUR|\tGBP|\tRUB|\tUSD|\n");      //Creating header for chart
amountUsd = userAmount * UsdToAud;      //converting given amount to usd before converting it to other currencies through functions besides the given one, and usd
printf("AUD:|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\n",userAmount,convertCad(amountUsd),convertEur(amountUsd),convertGbp(amountUsd),convertRub(amountUsd),amountUsd); //converting and outputting converted currencies with standadized spacing
amountUsd = userAmount * UsdToCad;      //converting given amount to usd before converting it to other currencies through functions besides the given one, and usd
printf("CAD:|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\n",convertAud(amountUsd),userAmount,convertEur(amountUsd),convertGbp(amountUsd),convertRub(amountUsd),amountUsd); //converting and outputting converted currencies with standadized spacing
amountUsd = userAmount * UsdToEur;      //converting given amount to usd before converting it to other currencies through functions besides the given one, and usd
printf("EUR:|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\n",convertAud(amountUsd),convertCad(amountUsd),userAmount,convertGbp(amountUsd),convertRub(amountUsd),amountUsd); //converting and outputting converted currencies with standadized spacing
amountUsd = userAmount * UsdToGbp;      //converting given amount to usd before converting it to other currencies through functions besides the given one, and usd
printf("GBP:|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\n",convertAud(amountUsd),convertCad(amountUsd),convertEur(amountUsd),userAmount,convertRub(amountUsd),amountUsd); //converting and outputting converted currencies with standadized spacing
amountUsd = userAmount * UsdToRub;      //converting given amount to usd before converting it to other currencies through functions besides the given one, and usd
printf("RUB:|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\n",convertAud(amountUsd),convertCad(amountUsd),convertEur(amountUsd),convertGbp(amountUsd),userAmount,amountUsd); //converting and outputting converted currencies with standadized spacing
amountUsd = userAmount;                 //converting given amount to usd before converting it to other currencies through functions besides the given one, and usd
printf("USD:|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\t%4.2f|\n",convertAud(amountUsd),convertCad(amountUsd),convertEur(amountUsd),convertGbp(amountUsd),convertRub(amountUsd),userAmount); //converting and outputting converted currencies with standadized spacing

}