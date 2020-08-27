/* Increment to Top @ https://edabit.com/challenge/433u4ZLXjR6DnNhnK
**
** Create a function that returns the total number of steps it takes to transform each element to the maximal
** element in the array. Each step consists of incrementing a digit by one.
** */

#include <algorithm>
#include <numeric>
#include <vector>

int incrementToTop(std::vector<int> arr) {
	int largest = std::accumulate(arr.begin(), arr.end(), arr.at(0), [](const int& prev, const int& curr) -> int{
		return curr > prev ? curr : prev;
	});

	int distance_sum = std::accumulate(arr.begin(), arr.end(), 0, [&largest](const int& prev, const int& curr) -> int {
		return prev + (largest - curr);
	});

	return distance_sum;
}
