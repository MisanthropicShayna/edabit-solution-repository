/* Nth Smallest Element @ https://edabit.com/challenge/J3heQdX8zwaNZWaj9
**
** Given an unsorted array, create a function that returns the nth smallest element
** (the smallest element is the first smallest, the second smallest element is the second smallest, etc).
** */

#include <algorithm>
#include <vector>

int nthSmallest(std::vector<int> array, int number) {
    std::sort(array.begin(), array.end());
    return number - 1 < array.size() ? array[number - 1] : -1;
}
