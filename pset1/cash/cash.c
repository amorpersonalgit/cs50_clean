/********************/
/* Greddy Algorithm */
/********************/

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int counter;

int main(void) {
    float change;

    do {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    int n = round(change * 100);

    while (n >= 25) {
        n -= 25;
        counter++;
    }

    while (n >= 10) {
        n -= 10;
        counter++;
    }

    while (n >= 5) {
        n -= 5;
        counter++;
    }

    while (n >= 1)  {
        n -= 1;
        counter++;
    }
    printf("%i\n", counter);

    return 0;
}
