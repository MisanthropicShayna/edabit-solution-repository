 /* Letters Shared Between Two Words
 **
 ** Create a function that returns the number of characters shared between two words.
 ** */

#include <numeric>
#include <string>

int sharedLetters(std::string str1, std::string str2) {
    return std::accumulate(str1.begin(), str2.end(), 0, [&str2](int& acc, char& curr) -> int {
        return str2.find(curr) != std::string::npos ? acc + 1 : acc;
    });
}
