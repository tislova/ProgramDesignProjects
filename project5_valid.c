/*Adeliya Tislova
The program takes input from the user as command line arguments, determines if it is valid using ctype library*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{  
    if (argc < 2) //Validate the number of arguments
    {
        printf("invalid number of arguments\n");
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        int j = 0;
        char *arg = argv[i];
        while (arg[j] != '\0') //User input ends with pressing enter
        {
            char c = arg[j];
            if (isupper(c) || (ispunct(c) && c != '!' && c != '?' && c != '.')) //Condition for invalid input
            {
                printf("invalid\n");
                return 1;
            } 
            else if (isalpha(c) || isdigit(c) || isspace(c) || c == '!' || c == '?' || c == '.') //Condition for valid input
            {
                j++;
                continue;
            } 
            else 
            {
                printf("invalid\n");
                return 1;
            }
        }
    }
    printf("valid\n");
    return 0;
}