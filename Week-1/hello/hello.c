#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? "); //Getting the user input
    printf("Hello, %s\n", name); // Recall the user input
}