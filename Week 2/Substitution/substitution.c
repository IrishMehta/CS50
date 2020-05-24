#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        for (int i = 0, n = strlen(argv[1]); i < n ; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    return 1;
                }
            }
            if (isalpha(argv[1][i]) == 0)
            {
                return 1;
            }
        }
        string plaintext = get_string("plaintext:  ");
        int index;

        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i]))
            {
                index = (int)plaintext[i];
                if (index >= 97)
                {
                    int key_index = index - 97;
                    plaintext[i] = tolower(argv[1][key_index]);

                } else if (index >= 65)
                {
                    int key_index = index - 65;
                    plaintext[i] = toupper(argv[1][key_index]);
                }
            }
        }
        printf("ciphertext: %s\n", plaintext);

    } else if (argc == 2 && strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    } else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}