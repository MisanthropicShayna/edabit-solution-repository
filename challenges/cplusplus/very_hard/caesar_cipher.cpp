/* Caesar's Cipher @ https://edabit.com/challenge/GmPfqu2jmLDBD2NYS
**
** Julius Caesar protected his confidential information by encrypting it using a cipher.
** Caesar's cipher (check Resources tab for more info) shifts each letter by a number of letters.
** If the shift takes you past the end of the alphabet, just rotate back to the front of the alphabet.
** In the case of a rotation by 3, w, x, y and z would map to z, a, b and c.
** Create a function that takes a string s (text to be encrypted) and an integer k (the rotation factor).
** It should return an encrypted string.
** */

#include <algorithm>
#include <string>

std::string caesarCipher(std::string string, int shift) {
    std::transform(string.begin(), string.end(), string.begin(), [&shift](char character) -> char {
        char head_character = (character >= 'A' && character <= 'Z') ? 'A' : ((character >= 'a' && character <= 'z') ? 'a' : '\0');
        return head_character ? (head_character + (((character - head_character) + shift) % 26)) : character;
    });

    return string;
}
