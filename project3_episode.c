/*Adeliya Tislova
The program takes watched episodes as input and outputs a missing one using arrays.*/
#include <stdio.h>
#include <stdbool.h>

int getMissing(int watched[], int amount);

// Input and output
int main()
{
    int amount;
    printf("Enter number of episodes: ");
    scanf("%i", &amount);
    amount = amount - 1;
    int watched[amount];

    printf("Enter episodes watched: ");
    for (int i = 0; i < amount; i++)
    {
        scanf("%i", &watched[i]);
    }

    int missing_episode = getMissing(watched, amount);
    printf("Missing episode: %i\n", missing_episode);

    return 0;
}

// Determines a missing episode
int getMissing(int watched[], int amount)
{
    bool flag;
    for (int i = 1; i <= amount; i++)
    {
        flag = false;
        for (int j = 0; j < amount; j++)
        {
            if (watched[j] == i)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            {
                return i; // Return the missing episode
            }
    }
    return amount + 1; // If the missing episode is the last one
}