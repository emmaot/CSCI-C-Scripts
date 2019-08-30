#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shift(char c);

int main(int argc, string argv[])
{
    // Only pass one argument for key
    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return (1);
    }
    char character;
    string key_phrase = argv[1];
    // Validate and parse key
    for (int i = 0; i < strlen(key_phrase); i++)
    {
        character = argv[1][i];
        if ((character < 'A' || character > 'z') ||
         ((character > 'Z' && character < 'a')))
    {
           printf("Usage: ./vigenere keyword\n");
           return (1);
        }
    }

    // Cipher
    string message = get_string("Plaintext: ");
    char c;
    int shifted, cipher, key;
    int key_position = 0;
    printf("Ciphertext: ");
    for (int i = 0; message[i] != '\0'; i++)
    {
        c = message[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            key = shift(key_phrase[key_position]);
    // Process uppercase character
    if (isupper(c))
     {
        shifted = shift(c);
        cipher = (shifted + key) % 26;
        cipher = cipher + 'A';
     }
    // Process lower case character
    else if (islower(c))
    {
        shifted = shift(c);
        cipher = (shifted + key) % 26;
        cipher = cipher + 'a';
    }
        printf("%c", cipher);
        key_position = (key_position + 1) % strlen(key_phrase);
    }
    // Process other characters
    else
    {
        printf("%c", c);
    }
   }
    printf("\n");
}
// Shift function
int shift(char c)
{
    int shifted = 0;
    if (isupper(c))
   {
        // Processes upper case character
        shifted = c - 'A';
    }
        // Process lower case character
        else if (islower(c))
        {
            shifted = c - 'a';
        }
    return(shifted);
}
