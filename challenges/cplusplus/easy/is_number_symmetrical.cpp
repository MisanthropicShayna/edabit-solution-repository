/* Is the Number Symmetrical?  @ https://edabit.com/challenge/ypWB4DdqyPyC2NRh7
**
** Create a function that takes a number as an argument
** and returns true or false depending on whether the
** number is symmetrical or not. A number is symmetrical
** when it is the same as its reverse.
** */

#include <algorithm>
#include <string>

bool isSymmetrical(int num) {
    const std::string& forward = std::to_string(num);

    std::string reversed(forward);
    std::reverse(reversed.begin(), reversed.end());

    return forward == reversed;
}
