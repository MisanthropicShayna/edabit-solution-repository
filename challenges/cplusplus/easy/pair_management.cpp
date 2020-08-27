/* Pair Management @ https://edabit.com/challenge/adyFtG9tadPWPhmAQ
**
** Given a pair, return its FIRST value and its SECOND value. Pair will be < int, int >.
** */

#include <vector>

std::vector<int> pairs(std::pair <int, int> pair) {
    return {pair.first, pair.second};
}
