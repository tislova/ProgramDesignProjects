/*Adeliya Tislova
The program reads an input file, creates an output file, and writes words written twice in a row.*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 101

int is_square(char * word);

int main() {
    char file_name[MAX_LENGTH];
    printf("Enter file name: ");
    scanf("%100s", file_name); //Takes input form the user

    FILE *file_input = fopen(file_name, "r"); //Open an input file
    if (file_input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *file_output = fopen("output.txt", "w"); //Create an output file for writing
        if (file_output == NULL) {
        printf("Error creating output file.\n");
        fclose(file_input);
        return 1;
    }

    char word[MAX_LENGTH]; 
    while (fscanf(file_input, "%100s", word) != EOF) {
        if (is_square(word)) {
            fprintf(file_output, "%s\n", word); //Write to the output file
        }
    }

    fclose(file_input);
    fclose(file_output);
    return 0;
}

//Checks if the word is written twice in a row
int is_square(char * word) {
    int length = strlen(word);
    if (length % 2 != 0)
        return 0;

    int half = length / 2;
    for (int i = 0; i < half; i++) {
        if (word[i] != word[i + half]) //Iterate over each half of the word
            return 0;
    }
    return 1;
}