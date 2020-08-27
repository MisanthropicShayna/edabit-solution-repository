/* Get Word Count @ https://edabit.com/challenge/2RZXNLZMNMnGtS5d5
**
** Create a function that takes a string and returns the word count. The string will be a sentence.
** */

#include <algorithm>
#include <string>

int countWords(std::string str) {
    int space_count = std::count(str.begin(), str.end(), ' ');
    return space_count + 1;
}
