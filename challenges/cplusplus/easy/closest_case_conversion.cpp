/* Upper or Lower Case @ https://edabit.com/challenge/hqAcxshy4htn8RYJF
**
** Return the smallest number of steps it takes to convert a string entirely into
** uppercase or entirely into lower case, whichever takes the fewest number of steps.
** A step consists of changing one character from lower to upper case, or vice versa.
** */

#include <string>

int stepsToConvert(std::string str) {
    int lower_count = 0;
    int upper_count = 0;

    for(char& character : str) {
        if(character >= 'A' && character <= 'Z') ++upper_count;
        if(character >= 'a' && character <= 'z') ++lower_count;
    }

    return
        (lower_count && upper_count)
            ? (lower_count < upper_count ? lower_count : upper_count)
            : 0;
}
