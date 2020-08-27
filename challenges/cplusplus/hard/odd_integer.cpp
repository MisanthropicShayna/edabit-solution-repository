/* Find the Odd Integer @ https://edabit.com/challenge/wgnmQTbfssuhvZHqe
**
** Create a function that takes an array and finds the integer which appears an odd number of times.
** */

#include <vector>
#include <map>

int findOdd(std::vector<int> array) {
    std::map<int, int> occurence_counter;

    for(int& integer : array) {
        if(occurence_counter.count(integer)) {
            occurence_counter[integer] += 1;
        } else {
            occurence_counter[integer] = 1;
        }
    }

    for(auto& pair : occurence_counter) {
        if(pair.second % 2 == 1) return pair.first;
    }

    return 0;
}
