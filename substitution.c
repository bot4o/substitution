#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_LENGTH 26

bool validate(string key);

void encrypt(const string plaintext, const string key, string ciphertext);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!validate(argv[1]))
    {
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext) + 1];

    encrypt(plaintext, key, ciphertext);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
bool validate(string key)
{
    if (strlen(key) != ALPHABET_LENGTH)
    {
        return false;
    }
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if (isalpha(key[i]))
        {
            continue;
        }
        else
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        for (int j = 0; j < ALPHABET_LENGTH; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (key[j] == key[i])
            {
                printf("Key must not contain repeated characters.");
                return false;
            }
            else
            {
                continue;
            }
        }
    }
    return 1;
}
void encrypt(const string plaintext, const string key, string ciphertext)
{
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char current = plaintext[i];

        if (isalpha(current))
        {
            int index = tolower(current) - 'a';
            char substitude = key[index];

            if (isupper(current))
            {
                ciphertext[i] = toupper(substitude);
            }
            else
            {
                ciphertext[i] = tolower(substitude);
            }
        }
        else
        {
            ciphertext[i] = current;
        }
    }
    // terminate
    ciphertext[strlen(plaintext)] = '\0';
}
