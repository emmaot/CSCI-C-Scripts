#include <stdio.h>
#include <cs50.h>
int main()
{
    // ask user for pyramid size
    int width = 0;
    while (width < 1 || width > 8)
    {
        width = get_int("Height: ");
    }
    //This creates an outer loop for the rows
    for (int height = 1; height <= width; height++)
    {   
        //This adds spaces on the left so it's not right to left.
        for (int space = 0; space < width - height; space++)
        {
            printf(" ");
        }
        //This creats the blocks
        for (int column = 1; column <= height; column++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
