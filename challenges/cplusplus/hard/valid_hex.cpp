/* Valid Hex Code @ https://edabit.com/challenge/ZhEBoaEfMcK6vT7Kx
**
** Create a function that determines whether a string is a valid hex code.
**
** A hex code must begin with a pound key # and is exactly 6 characters in length.
** Each character must be a digit from 0-9 or an alphabetic character from A-F.
** All alphabetic characters may be uppercase or lowercase.
** */

#include <algorithm>
#include <string>

bool isValidHexCode(std::string str) {
    if(str.size() && str[0] != '#') return false;
    if(str.size() != 7) return false;

    if(std::any_of(str.begin(), str.end(), [](char& character) -> bool {
        return !((character >= 'A' && character <= 'F') ||
                 (character >= 'a' && character <= 'f') ||
                 (character >= '0' && character <= '9') ||
                 (character == '#'));

    })) return false;

    return true;
}
