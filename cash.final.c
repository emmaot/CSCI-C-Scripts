#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float change_float = -1.0;
while(change_float < 0)
    {
        change_float = get_float("Change owed: ");
    }
    int change = round(100.0 * change_float);

    int num_coins = 0;
    
while (change >= 25)
    {
        num_coins = num_coins + 1;
        change = change - 25;
    }
while (change >= 10)
    {
        num_coins = num_coins + 1;
        change = change - 10;
    }
while (change >= 5)
    {
        num_coins = num_coins + 1;
        change = change - 5;    
    }
while (change >= 1)
    {
        num_coins = num_coins + 1;
        change = change - 1;
    }
    printf("You need %d coins\n", num_coins);
}
