/* Atbash Cipher @ https://edabit.com/challenge/977xgdi57bp23ibz5
**
** The Atbash cipher is an encryption method in which each letter of a word is
** replaced with its "mirror" letter in the alphabet: A <=> Z; B <=> Y; C <=> X; etc.
** Create a function that takes a string and applies the Atbash cipher to it.
** */

#include <algorithm>
#include <string>

std::string atbash(std::string string) {
    std::transform(string.begin(), string.end(), string.begin(), [](char& character) -> char {
        return
            (character >= 'A' && character <= 'Z') ?
                (character <= 'M' ? 'Z' - (character - 'A') : 'A' + ('Z' - character)) :
            (character >= 'a' && character <= 'z') ?
                (character <= 'm' ? 'z' - (character - 'a') : 'a' + ('z' - character)) :
            character;
    });

    return string;
}
