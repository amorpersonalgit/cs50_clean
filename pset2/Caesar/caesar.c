#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char *usage = "Usage ./caesar key\n";

    if (argc != 2) {
        printf("%s", usage);
        return 1;
    }
    int key = atoi(argv[1]);
    for (int i = 1; i < 6; i++) {
        if (key == i * 26) {
            printf("%i Can't be key\n", key);
            return 2;
        }
    }

    for (int i = 0, key_lenght = strlen(argv[1]); i < key_lenght; i++) {
        if (!isdigit(argv[1][i])) {
            printf("%s", usage);
            return 3;
        }
    }

    char *plain_text = get_string("Plaintext: ");
    printf("Ciphertext: ");

    // Encipher
    for (int i = 0, n = strlen(plain_text); i < n;  i++)
    {
        if (islower(plain_text[i]))
        {
            printf("%c", 'a' + (plain_text[i] - 'a' + key) % 26);
        }
        else if (isupper(plain_text[i]))
        {
            printf("%c", 'A' + (plain_text[i] - 'A' + key) % 26);
        }
        else if (!isalpha(plain_text[i]))
        {
            printf("%c", plain_text[i]);
        }
        else
        {
            return 4;
        }
    }
    printf("\n");
    return 0;
}
