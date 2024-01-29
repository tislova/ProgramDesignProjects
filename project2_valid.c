/*Adeliya Tislova
The program takes input from the user, determines if it is valid using ctype library*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{  
    int c;
    printf("Enter input: ");

    while ((c = getchar()) != '\n') //User input ends with pressing enter
    {
        if (isupper(c) || (ispunct(c) && c != '!' && c != '?' && c != '.')) //Condition for invalid input
        {
            printf("invalid\n");
            return 1;
        } 
        else if (isalpha(c) || isdigit(c) || isspace(c) || c == '!' || c == '?' || c == '.') //Condition for valid input
        {
            continue;
        } 
        else 
        {
            printf("invalid\n");
            return 1;
        }
    }

    printf("valid\n");
    return 0;
}