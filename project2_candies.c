/*Adeliya Tislova
The program simulates vending machine. It takes input from the user and outputs the amount of change.*/

#include <stdio.h>

#define STOP 0
#define HERSHEYS 15
#define REESES 25
#define SNICKERS 50

//Obtains the amount of inserted coins
int getCoins();
//Calculates change or detects insufficient amount based on selection choice
int getChange(int amount, int choice);

int main(void)
{
    int choice;
    int amount = getCoins();
    printf("1 - Hershey's kisses (15 cents), 2 - Reese's Peanut Butter Cups (25 cents), 3 - Snickers (50 cents)\n");
    printf("Enter your choice:");
    scanf("%i", &choice);
    if (choice > 0 && choice < 4) //Input validation
    {
    getChange(amount, choice);
    }
    else
    {
        printf("Invalid selection, %i cents returned\n", amount);
    }
    return 0;
}

int getCoins()
{
    int user_input;
    int coins = 0;
    do
    {
        printf("Insert coins: ");
        scanf("%i", &user_input);
        coins += user_input;

    } while (user_input != STOP);
    
    return coins;
}

int getChange(int amount, int choice)
{
    int change;
    int temp;
    switch (choice)
    {
        case 1:
        temp = amount / HERSHEYS;
        change = amount - HERSHEYS * temp;
        if (change == amount)
        {
            printf("Insufficient amount, %i cents returned\n", amount);
            return 1;
        }
        else
        {
            printf("Your change is %i cents\n", change);
            return 0;
        }
        break;

        case 2:
        temp = amount / REESES;
        change = amount - REESES * temp;
        if (change == amount)
        {
            printf("Insufficient amount, %i cents returned\n", amount);
            return 1;
        }
        else
        {
            printf("Your change is %i cents\n", change);
            return 0;
        }
        break;

        case 3:
        temp = amount / SNICKERS;
        change = amount - SNICKERS * temp;
        if (change == amount)
        {
            printf("Insufficient amount, %i cents returned\n", amount);
            return 1;
        }
        else
        {
            printf("Your change is %i cents\n", change);
            return 0;
        }
        break;
    }
    return 0;
}