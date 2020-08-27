/* Filter by Digit Length @ https://edabit.com/challenge/a5uCzYhMuENz4BvgT
**
** Create a function that filters out an array to include numbers which only have a certain number of digits.
** */

#include <algorithm>
#include <vector>
#include <cmath>

std::vector<int> filterDigitLength(std::vector<int> arr, int n) {
    std::vector<int> filtered;

    std::copy_if(arr.begin(), arr.end(), std::back_inserter(filtered), [&n](int& value) -> bool {
        return floor(log10(value))+1 == n;
    });

    return filtered;
}
