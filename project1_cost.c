/*Adeliya Tislova
The program takes inputs form the user and calculates the total charge of the event using functions*/

#include <stdio.h>
#include <stdlib.h>

//Obtain a valid package number from the user
int getSelection();
//Obtain a valid number of hours
int getHours();
//Obtain a valid number of guests based on the package number
int getGuests(int selection_choice);

int main(void)
{
    int selection_choice = getSelection();
    int selection_hours = getHours();
    int selection_guests = getGuests(selection_choice);
    int total_charge;
    int max1 = 595; //Maximum value of charge of the first package
    int max2 = 850;
    int max3 = 1050;

    switch (selection_choice) //Calculate total_charge based on the package number
    {
        case 1: 
        total_charge = 150 + 100 * (selection_hours - 1) + 25 * selection_guests;
        if (total_charge > max1)
        {
            printf("Charge($):%i\n", max1); //Print out the maximum charge if total_charge exceeds
            return 0;
        }
        break;

        case 2: 
        total_charge = 180 + 120 * (selection_hours - 1) + 22 * selection_guests;
        if (total_charge > max2)
        {
            printf("Charge($):%i\n", max2);
            return 0;
        }
        break;

        case 3: 
        total_charge = 200 + 150 * (selection_hours - 1) + 20 * selection_guests;
        if (total_charge > max3)
        {
            printf("Charge($):%i\n", max3);
            return 0;
        }
        break;
    }

    printf("Charge($):%i\n", total_charge);

    return 0;
}

int getSelection()
{
    int package_number;
    printf("Please select from three packages: 1, 2, and 3\nEnter package selection:");
    scanf("%i", &package_number);

    if (package_number < 1 || package_number > 3)
    {
        printf("Invalid selection.\n");
        exit(1);
    }

    return package_number;
}

int getHours()
{
    int hours_number;
    printf("Enter hours:");
    scanf("%i", &hours_number);

    if (hours_number < 1 || hours_number > 4)
    {
        printf("Invalid hours.\n");
        exit(2);
    }

    return hours_number;
}

int getGuests(int selection_choice)
{
    int guests_number;
    printf("Enter the number of guests: ");
    scanf("%i", &guests_number);

    if (selection_choice == 1 && (guests_number < 5 || guests_number > 20))
    {
        printf("Invalid number of guests.\n");
        exit(3);
    }
    else if (selection_choice == 2 && (guests_number < 8 || guests_number > 30))
    {
        printf("Invalid number of guests.\n");
        exit(3);
    }
    else if (selection_choice == 3 && (guests_number < 10 || guests_number > 40))
    {
        printf("Invalid number of guests.\n");
        exit(3);
    }
    else
    {
        return guests_number;
    }
}