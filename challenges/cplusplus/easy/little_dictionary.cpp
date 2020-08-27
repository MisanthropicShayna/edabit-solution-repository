/* Little Dictionary @ https://edabit.com/challenge/vEYHYa6ufpz5o3ruE
**
** Create a function that takes in an initial word and filters out an array
** which contains words that start with the same letters as the initial word.
** */

#include <algorithm>
#include <vector>
#include <string>

std::vector<std::string> dictionary(std::string initial, std::vector<std::string> words) {
    std::vector<std::string> filtered_words;

    std::copy_if(words.begin(), words.end(), std::back_inserter(filtered_words), [&initial](const std::string& word) -> bool {
        return word.find(initial) == 0;
    });

    return filtered_words;
}
