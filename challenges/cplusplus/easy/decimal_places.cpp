/* How Many Decimal Places? @ https://edabit.com/challenge/YzR5LWPz3XkDJdoeu
**
** Create a function that returns the number of decimal places a number (given as a string) has.
** Any zeros after the decimal point count towards the number of decimal places.
 */

#include <algorithm>
#include <string>

int getDecimalPlaces(std::string number) {
    auto decimal_position = number.find('.');

    if(decimal_position != std::string::npos) {
        return std::distance(number.begin() + decimal_position + 1, num.end());
    } else {
        return 0;
    }
}
