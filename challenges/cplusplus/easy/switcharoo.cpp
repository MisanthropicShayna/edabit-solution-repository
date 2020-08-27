/* Switcharoo @ https://edabit.com/challenge/7WrM5GcpzZQwfmMQz
**
** reate a function that takes a string and returns a new string with its first and last characters swapped,
** except under two conditions:
**
** If the length of the string is less than two, return "Incompatible.".
** If the first and last characters are the same, return "Two's a pair.".
** */

#include <string>

std::string flipEndChars(std::string str) {
    if(str.size() < 2) return "Incompatible.";
    if(str.at(0) == str.at(str.size()-1)) return "Two's a pair.";
    std::iter_swap(str.begin(), str.end()-1);
    return str;
}
