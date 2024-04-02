/*Adeliya Tislova
The program takes input from the user, searches the supply in the csv file, and then writes to the output file
using structs and functions.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 101
#define MAX_SUPPLY 200

//Struct declaration
struct supply {
    char name[MAX_LENGTH];
    char color[MAX_LENGTH];
    int quantity;
};

int search(struct supply list[], int n, struct supply result[], char *search_name);
char *read_line(char *input_name, size_t max_length);

int main() {
    struct supply supply_input[MAX_SUPPLY];
    struct supply supply_output[MAX_SUPPLY];
    char file_name[] = "supply.csv";
    char search_name[MAX_LENGTH];

    FILE *file_input = fopen(file_name, "r"); //Open an input file
    if (file_input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *file_output = fopen("result.csv", "w"); //Create an output file for writing
        if (file_output == NULL) {
        printf("Error creating output file.\n");
        fclose(file_input);
        return 1;
    }
 
    printf("Enter supply: ");
    read_line(search_name, MAX_LENGTH);

    //Count the amount of supplies
    int amount = 0;
    while (fscanf(file_input, "%100[^,], %100[^,], %d\n", supply_input[amount].name, supply_input[amount].color, &supply_input[amount].quantity) == 3) {
        amount++;
    }

    int num_supplies = search(supply_input, amount, supply_output, search_name);

    //Write to the output file results from the search function
    for (int i = 0; i < num_supplies; i++) {
        fprintf(file_output, "%s, %s, %d\n", supply_output[i].name, supply_output[i].color, supply_output[i].quantity);
    }

    //Close files
    fclose(file_input);
    fclose(file_output);
    return 0;
}

//Scan input from the user
char *read_line(char *input_name, size_t max_length) {
    fgets(input_name, max_length, stdin);

    //Change newline character to '\0'
    size_t length = strlen(input_name);
    if (input_name[length - 1] == '\n') {
        input_name[length - 1] = '\0';
    }

    return input_name;
}

//Search for the matching name and store in the array result
int search(struct supply list[], int n, struct supply result[], char *search_name)
{
    int num_supplies = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].name, search_name) == 0) {
            strcpy(result[num_supplies].name, list[i].name);
            strcpy(result[num_supplies].color, list[i].color);
            result[num_supplies].quantity = list[i].quantity;
            num_supplies++;
        }
    }
    return num_supplies;
}