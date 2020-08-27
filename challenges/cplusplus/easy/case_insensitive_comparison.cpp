/* Case Insensitive Comparison @ https://edabit.com/challenge/ZbhnvGYsHRuXA4kkY
**
** Write a function that validates whether two strings are identical. Make it case insensitive.
** */

#include <algorithm>
#include <string>

bool match(std::string string1, std::string string2) {
    std::transform(string1.begin(), string1.end(), string1.begin(), [](char character) -> char {
        return (character >= 'A' && character <= 'Z') ? character + 32 : character;
    });

    std::transform(string2.begin(), string2.end(), string2.begin(), [](char character) -> char {
        return (character >= 'A' && character <= 'Z') ? character + 32 : character;
    });

    return string1 == string2;
}
