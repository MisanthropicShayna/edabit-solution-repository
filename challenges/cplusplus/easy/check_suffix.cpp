/* Check if String Ending Matches Second String @ https://edabit.com/challenge/TmKLt7deZHgFhez8j
**
** Create a function that takes two strings and returns true if the
** first string ends with the second string; otherwise return false.
** */

#include <string>

bool checkEnding(std::string str1, std::string str2) {
    return str1.find(str2, str1.size() - str2.size()) != std::string::npos;
}
