#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number;

    do {
        printf("Height: ");
        scanf("%i", &number);
    }
    while (number < 1 || number > 8);

    for (int i = 1; i <= number; i++) {
        for (int sp = number - i; sp > 0; sp--) {
            printf(" ");
        }
        for (int hash = 0; hash < i; hash++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
