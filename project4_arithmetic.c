/*Adeliya Tislova
The program takes input as an array and determines if it is an arithmetic sequence using pointers.*/
#include <stdio.h>

int is_arithmetic_sequence(int *sequence,  int n);

//Input and output
int main()
{
    int n;
    printf("Enter length of the sequence: ");
    scanf("%i", &n);

    int sequence[n];

    printf("Enter numbers of the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%i", &sequence[i]);
    }

    int flag = is_arithmetic_sequence(sequence, n);

    if (flag)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}

//Calculates difference and compares with the rest of the elements
int is_arithmetic_sequence(int *sequence,  int n)
{
    int *sequence_end = sequence + n - 1;

    int factor = *(sequence + 1) - *sequence;

    while (sequence < sequence_end)
    {
        if (factor != (*(sequence + 1) - *sequence)) //Compare with the next
        {
            return 0;
        }
        sequence++;
    }

    return 1;
}