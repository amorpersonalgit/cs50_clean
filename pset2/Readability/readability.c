#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float letter_counter = 0, word_counter =1, senctence_counter = 0;

int main (void) {
    char *text = get_string("Text: ");

    int lenght = strlen(text);

    for (int i = 0; i < lenght; i++) {

        if (isalpha(text[i])) {
            letter_counter++;
        }
        else if (isspace(text[i]) || isblank(text[i])) {
            word_counter++;
        }
        else if (i > 0 && (text[i]  == '!' || text[i] == '?' || text[i] == '.')) {
            senctence_counter++;
        }
    }

    float index = roundf(0.0588 * (100 * letter_counter /
                word_counter) - 0.296 * (100 * senctence_counter /
                    word_counter) - 15.8);

    if (index <= 1) {
        printf("Before Grade 1\n");
    }
    else if (index < 16){
        printf("Grade %.f\n", index);
    }
    else {
        printf("Grade 16+\n");
    }

    return 0;
}
