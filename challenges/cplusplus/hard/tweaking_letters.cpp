/* Tweaking Letters @ https://edabit.com/challenge/868Q9JmTSAEhZBBrg
**
** Create a function that tweaks letters by one forward (+1) or backwards (-1) according to an array.
** */

#include <vector>
#include <string>

std::string tweakLetters(std::string string, std::vector<int> array) {
    for(size_t i=0; i<string.size(); i++) {
        char& character = string.at(i);

        if(array.at(i) == -1) {
            character = character == 'a' ? 'z' : character - 1;
        } else if(array.at(i) == 1) {
            character = character == 'z' ? 'a' : character + 1;
        }
    }

    return string;
}
