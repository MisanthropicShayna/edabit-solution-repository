/* Double Character Swap @ https://edabit.com/challenge/s695FkhRd3J65tmdQ
**
** Write a function to replace all instances of character c1 with character c2 and vice versa.
** */

#include <algorithm>
#include <string>

std::string doubleSwap(std::string string, char character_1, char character_2) {
    std::transform(string.begin(), string.end(), string.begin(), [&character_1, &character_2](char& current_character) -> char {
        return current_character == character_1 ? (character_2) : (current_character == character_2 ? (character_1) : (current_character));
    });

    return string;
}
