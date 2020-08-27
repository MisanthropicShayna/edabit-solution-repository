/* Find Number of Digits in Number @ https://edabit.com/challenge/fYGY3kBJvHmo94Qap
**
** Create a function that will return an integer number containing
** the amount of digits in the given integer num.
** */

#include <cmath>

int numOfDigits(int num) {
    int digit_counter = 0;

    for(digit_counter;num != 0; num /= 10) {
        ++digit_counter;
    }

    if(digit_counter == 0) digit_counter++;
    return digit_counter;
}
