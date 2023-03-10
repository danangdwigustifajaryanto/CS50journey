#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height; // declare a variable to store the pyramid height
    do // repeat the following block of code until the user enters a valid input
    {
        height = get_int("Height: "); // prompt the user for the pyramid height
    }
    while (height < 1 || height > 8); // continue prompting until the user enters a number between 1 and 8, inclusive

    for (int row = 0; row < height; row++) // loop over each row of the pyramid
    {
        for (int col = 0; col < height; col++) // loop over each column of the pyramid
        {
            if (col >= height - (row + 1)) // determine whether to print a space or a hash based on the current row and column
            {
                printf("#"); // print a hash
            }
            else
            {
                printf(" "); // print a space
            }
        }
        printf("\n"); // start a new line for the next row of the pyramid
    }
}
