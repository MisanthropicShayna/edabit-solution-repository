/* Split Item Codes @ https://edabit.com/challenge/rGAQ4xEHgD37pfWoa
**
** You have an array of item codes with the following format: "[letters][digits]"
** Create a function that splits these strings into their alphabetic and numeric parts.
** */

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

std::vector<std::string> splitCode(std::string item) {
    std::string alpha(std::accumulate(item.begin(), item.end(), 0, [](const int& acc, const char& curr) -> int {
        return (curr >= 'A' && curr <= 'Z') || (curr >= 'a' && curr <= 'z') ? acc + 1 : acc;
    }), '\0');

    std::string numeric(std::accumulate(item.begin(), item.end(), 0, [](const int& acc, const char& curr) -> int {
        return (curr >= '0' && curr <= '9') ? acc + 1 : acc;
    }), '\0');

    std::copy_if(item.begin(), item.end(), alpha.begin(), [](char curr) -> bool {
        return (curr >= 'A' && curr <= 'Z') || (curr >= 'a' && curr <= 'z');
    });

    std::copy_if(item.begin(), item.end(), numeric.begin(), [](char curr) -> bool {
        return (curr >= '0' && curr <= '9');
    });

    return {alpha, numeric};
}
