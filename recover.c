#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
	// ensure proper usae
	if (argc != 3)
	{
	fprintf(stderr, "Usage: ./recover image\n");
	return 1;
	}

	// Open the file in memory card
	FILE* input = fopen("card.raw", "r");
	if(input == NULL)
	{
		printf("Unable to open card.raw.\n");
		return 2;
	}
	
	// This creates the buffer
	unsigned char jpgBuffer(BUFFER_SIZE);

	//filename counter
	int filecount = 0;
	FILE* current_photo == NULL;

	int jpg.detect = 0;

	while(fread(jpgBuffer, BUFFER_SIZE, 1, input) == 1)
	{
	// Reads bytes
	if(jpgbuffer[0] == 0xff && jpgbuffer[1] == 0xd8 && jpgbuffer[2] == 
	0xff && (jpgbuffer[3] & 0xe0) == 0xe0)
	{
		if(jpg.detect == 1)
		{	
		}
		else
		{
			// Detects jpg and write to it
			jpg.detect == 1);
		}
	char filename[8];
	sprintf
}
