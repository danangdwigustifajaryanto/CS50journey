#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for a positive integer between 1 and 8 inclusive
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print pyramid
    for (int row = 0; row < height; row++)
    {
        // Print left pyramid
        for (int i = 0; i < height - row - 1; i++)
        {
            printf(" ");
        }
        for (int i = 0; i < row + 1; i++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print right pyramid
        for (int i = 0; i < row + 1; i++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
