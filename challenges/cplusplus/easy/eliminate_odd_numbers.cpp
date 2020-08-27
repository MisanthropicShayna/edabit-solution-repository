/* Eliminate Odd Numbers within an Array @ https://edabit.com/challenge/7iT6DbY3GsHnLBPq4
**
** Create a function that takes an array of numbers and returns only the even values.
** */

#include <algorithm>
#include <vector>

std::vector<int> noOdds(const std::vector<int>& vec) {
    std::vector<int> filtered_vector;

    std::copy_if(vec.begin(), vec.end(), filtered_vector.begin(), [](int i) -> bool {
        return i % 2 == 0;
    });

    return filtered_vector;
}
