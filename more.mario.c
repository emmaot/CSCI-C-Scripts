#include <stdio.h>
//#include <cs50.h>
int main()
{

    int width = 0;	
	while(width < 1 || width > 8){
		width = get_int("Height: ");
	}

    for(int height = 1; height <= width; height++)
    { 
		for ( int space = 0; space < width - height; space++){
			printf(" ");
		}
        for(int column = 1; column <= height; column++)
        {
            printf("#");
        }
        for(int column = 1; column <= height; column++)
        
        printf("\n");
    }
    return 0;
}
