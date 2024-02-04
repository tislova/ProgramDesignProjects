/*Adeliya Tislova
The program takes input as an array of points and outputs arrays based on the team assignment.*/
#include <stdio.h>
#include <stdlib.h>

#define BEGINNER 25
#define HONOR 70
#define EXCELLENCE 125

void assign(int points[], int team_assignment[],  int n);

// Input and output
int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%i", &n);

    int team_assignment[n];
    int points[n];

    printf("Enter points for each student: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &points[i]);
    }

    assign(points, team_assignment, n);

    printf("Beginner team: student ");
    for (int i = 0; i < n; i++) // Determines the number of the student in the beginner team
    {
        if (team_assignment[i] == 1)
        {
            printf("%i ", i + 1);
        }
    }
    printf("\n");

    printf("Honor team: student ");
    for (int i = 0; i < n; i++)
    {
        if (team_assignment[i] == 2)
        {
            printf("%i ", i + 1);
        }
    }
    printf("\n");

    printf("Excellence team: student ");
    for (int i = 0; i < n; i++)
    {
        if (team_assignment[i] == 3)
        {
            printf("%i ", i + 1);
        }
    }
    printf("\n");
}

// Calculates the absolute value and performs team assignment
void assign(int points[], int team_assignment[],  int n)
{
    for (int i = 0; i < n; i++)
    {
        int beginner = abs(points[i] - BEGINNER);
        int honor = abs(points[i] - HONOR);
        int excellence = abs(points[i] - EXCELLENCE);

        if (beginner <= honor && beginner <= excellence)
        {
            team_assignment[i] = 1;
        }
        else if (honor <= beginner && honor <= excellence)
        {
            team_assignment[i] = 2;
        }
        else
        {
            team_assignment[i] = 3;
        }
    }
}