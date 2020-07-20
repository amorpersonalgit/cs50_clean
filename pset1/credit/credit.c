#include <stdio.h>
#include <cs50.h>

int main (void) {

    long long cc_number = get_long_long("Number: ");

    int digit_1 = 0, digit_2 = 0, num_digits = 0;
    int sum_of_double_odds = 0, sum_of_evens = 0;

    while (cc_number > 0) {
        digit_2 = digit_1;
        digit_1 = cc_number % 10;

        if (num_digits % 2 == 0) {
            sum_of_evens += digit_1;
        }
        else {
            int multiple_of = 2 * digit_1;
            sum_of_double_odds += (multiple_of / 10) + (multiple_of % 10);
        }

        cc_number /= 10;
        num_digits++;
    }

    bool is_valid = (sum_of_evens + sum_of_double_odds) % 10 == 0;
    int first_two_digits = (digit_1 * 10) + digit_2;

    if (digit_1 == 4 && num_digits >= 13 && num_digits <= 16 && is_valid) {
        printf("VISA\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 &&
            num_digits == 16 && is_valid) {
        printf("MASTERCARD\n");
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) &&
            num_digits == 15 && is_valid) {
        printf("AMEX\n");
    }
    else {
        printf("INVALID\n");
    }
    return 0;
}
