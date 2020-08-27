/* State Names and Abbreviations @ https://edabit.com/challenge/9ugiNEhBmxSyDSPMW
**
** Create a function that filters out an array of state names into two categories based on the second parameter.
** */

#include <algorithm>
#include <vector>
#include <string>

std::vector<std::string> filterStateNames(std::vector<std::string> states, std::string type) {
    std::vector<std::string> filtered;

    std::copy_if(states.begin(), states.end(), std::back_inserter(filtered), [&type](const std::string& state) -> bool {
        return type == "abb" ? state.size() == 2 : (type == "full" ? state.size() > 2 : false);
    });

    return filtered;
}
