#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number;

    do {
        number = get_int("Height: ");
    }
    while(number < 1 || number > 8);

    for (int i = 1; i <= number; i++) {
        for (int sp = number - i; sp > 0; sp--) {
            printf(" ");
        }

        for (int lhash = 0; lhash < i; lhash++) {
            printf("#");
        }
        printf(" ");

        for (int rhash = 0; rhash < i; rhash++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
