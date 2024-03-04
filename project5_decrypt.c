/*Adeliya Tislova
The program takes input from the user and decrypts the message using pointers*/
#include <stdio.h>

void decrypt(char *input, char *output);

int main()
{
    char input[1001];
    char output[1001];
    printf("Enter message: ");
    for (int i = 0; i < 1000; i++) { //Store input in the array 
        scanf("%c", &input[i]);
        if (input[i] == '\n' || input[i] == EOF) {
            input[i] = '\0';
            break;
        }
    }
    decrypt(input, output);
    printf("Output: %s\n", output); //Print out the output
    return 0;
}

//Decrypt the message
void decrypt(char *input, char *output)
{
    char *p_input = input;
    char *p_output = output;
    int temp = 1;
    while (*p_input != '\0')
    {
        *p_output = *p_input;
        p_output++;
        for (int i = 0; i < temp; i++) //Skip characters
        {
            p_input++;
            if (*p_input == '\0')
                break;
        }
        temp++; // Increment the position counter
        p_input++; // Move to the next character
    }
    *p_output = '\0';
}