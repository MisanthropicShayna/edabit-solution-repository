/* Sum of Digits Between Two Numbers @ https://edabit.com/challenge/jwcuCiTMpeMQvfHkm
** Create a function that sums the total number of digits between two numbers, inclusive.
**
** For example, between the numbers 19 and 22 we have:
** (1 + 9) + (2 + 0) + (2 + 1) + (2 + 2) = 19
** */

#include <string>

int sumDigits(int a, int b) {
    int sum = 0;

    for(int i=a; i <= b; ++i) {
        std::string digits = std::to_string(i);

        for(char& digit : digits) {
            sum += (int)(digit - '0');
        }
    }

    return sum;
}
