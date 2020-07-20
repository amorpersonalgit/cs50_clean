#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define ABC "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MAX 26

int main(int argc, char *argv[])
{
    char user_key[MAX];

    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0; i < MAX; i++) {
        user_key[i] = argv[1][i];
    }

    int key_lenght = strlen(argv[1]);
    if (key_lenght != MAX) {
        printf("Key must contain %i characters.\n", MAX);
        return 2;
    }

    for (int i = 0; i < key_lenght; i++) {
        if (isalpha(user_key[i]) == 0) {
            printf("Key must contain only alphabetic characters.\n");
            return 3;
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (toupper(user_key[i]) == toupper(user_key[j]) && i != j) {
                printf("Key must contain unduplicated characters.\n");
                return 4;
            }
        }
    }

    char user_key_check[MAX];

    for (int i = 0; i < MAX; ++i) {
        user_key_check[i] = toupper(user_key[i]);
    }

    if (strcmp(user_key_check, ABC) == 0) {
        printf("Key can't be the abecedary!\n");
        return 5;
    }

    char *plain_text = get_string("Plaintext: ");

    printf("Ciphertext: ");

    // Encipher
    for (int i = 0; i < strlen(plain_text); i++) {
        if (isupper(plain_text[i])) {
            for (int j = 0; j < MAX; j++) {
                if (plain_text[i] == ABC[j]) {
                    printf("%c", toupper(user_key[j]));
                    break;
                }
            }
        }
        else if (islower(plain_text[i])) {
            for (int k = 0; k < MAX; k++) {
                if (toupper(plain_text[i]) == ABC[k]) {
                    printf("%c", tolower(user_key[k]));
                    break;
                }
            }
        }
        else {
            printf("%c", plain_text[i]);
        }
    }

    char cat [] = {0xF0, 0x9F, 0x98, 0xB8};
    printf("\n\n%s\n\n", cat);

    return 0;
}
