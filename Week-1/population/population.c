#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int n_start;
    do
    {
        n_start = get_int("Start Size: ");
    }
    while (n_start < 9);

    // Prompt for end size
    int n_end;
    do
    {
        n_end = get_int("End Size: ");
    }
    while (n_end < n_start);

    // Calculate number of years until we reach threshold
    int n = n_start; // Initialize current population
    int years = 0; // Initialize number of years

    while (n < n_end)
    {
        int born = n / 3;
        int dead = n / 4;
        n = n + born - dead;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}