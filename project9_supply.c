/*Adeliya Tislova
The program reads from the supply.csv and writes sorted supplies to the result.csv using qsort.*/

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

int sort(const void *p1, const void *p2);
char *read_line(char *input_name, size_t max_length);

int main() {
    struct supply supply_input[MAX_SUPPLY];
    char file_name[] = "supply.csv";

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

    //Count the amount of supplies
    int amount = 0;
    while (fscanf(file_input, "%100[^,], %100[^,], %d\n", supply_input[amount].name, supply_input[amount].color, &supply_input[amount].quantity) == 3) {
        amount++;
    }

    //Sort the array
    qsort(supply_input, amount, sizeof(struct supply), sort);

    //Write sorted array to the output file
    for (int i = 0; i < amount; i++) {
        fprintf(file_output, "%s, %s, %d\n", supply_input[i].name, supply_input[i].color, supply_input[i].quantity);
    }

    //Close files
    fclose(file_input);
    fclose(file_output);
    return 0;
}

//Comparison function for qsort
int sort(const void *p1, const void *p2) {
    const struct supply *supply1 = (const struct supply *)p1;
    const struct supply *supply2 = (const struct supply *)p2;
    if (strcmp(supply1->name, supply2->name) == 0) { //Determine if names are the same
        return strcmp(supply1->color, supply2->color); //Sort by color
    }
    return strcmp(supply1->name, supply2->name); //Sort by name
}