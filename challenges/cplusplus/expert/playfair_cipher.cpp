/* Playfair Cipher @ https://edabit.com/challenge/XdhAcbSJ3wsbiFHC7
**
** The Playfair cipher is a substitution cipher that uses digraphs (pairs of letters)
** instead of single letters, and makes use of symmetrical encryption.
**
** .. rest of the description has been omitted.
** */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Replaces the second character in symmetrical diagraphs in the input string with fill_char.
// Symmetrical diagraphs = diagraphs that are composed of the same character.
std::string RemoveSymmetricalDiagraphs(std::string& string, char fill_char = 'X') {

    for(int i=0; i<string.size(); ++i) {
        if(i % 2 != 0) {
            char& character = string[i];
            char& prev_char = string[i-1];

            if(character == prev_char) {
                string.insert(i, 1, fill_char);
                return RemoveSymmetricalDiagraphs(string, fill_char);
            }
        }
    }

    if(string.size() % 2 != 0) string.push_back('X');

    return string;
}

std::string playfair(std::string message, std::string keyword) {
    bool deciphering = std::all_of(message.begin(), message.end(), [](char& character) -> bool {
        return character >= 'A' && character <= 'Z';
    });

    std::cout << "Deciphering: " << deciphering << std::endl;




    // Create 5x5 Polybius  square.
    std::vector<std::vector<char>> cipher_grid(5);
    for(auto& row : cipher_grid) row.resize(5);




    // Only modify the message if it's plaintext.
    if(!deciphering) {
        // Upcases the message
        std::transform(message.begin(), message.end(), message.begin(), [](char character) -> char {
            return (character >= 'a' && character <= 'z') ? character - 32 : character;
        });

        // Replaces all J's with I's in the input message, to make them share a slot in the grid.
        std::transform(message.begin(), message.end(), message.begin(), [](char character) -> char {
            return character == 'J' ? 'I' : character;
        });

        std::string stripped_message_buffer;

        // Strips message of non-alphabetical characters.
        std::copy_if(message.begin(), message.end(), std::back_inserter(stripped_message_buffer), [](char character) -> bool {
            return character >= 'A' && character <= 'Z';
        });

        message = stripped_message_buffer;
    }




    // Upcases all lowercase characters in the keyword.
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), [](char character) -> char {
        return (character >= 'a' && character <= 'z') ? character - 32 : character;
    });

    std::transform(keyword.begin(), keyword.end(), keyword.begin(), [](char character) -> char {
        return character == 'J' ? 'I' : character;
    });

    std::string no_duplicates_buffer;

    // Store the keyword into modified_keyword, excluding duplicate characters.
    std::copy_if(keyword.begin(), keyword.end(), std::back_inserter(no_duplicates_buffer), [&no_duplicates_buffer](char character) -> bool {
        return no_duplicates_buffer.find(character) == std::string::npos && (character >= 'A' && character <= 'Z');
    });

    keyword = no_duplicates_buffer;



    std::cout << "Corrected message: " << message << std::endl;
    std::cout << "Corrected keyword: " << keyword << std::endl;


    size_t keyword_index = 0;

    std::string stripped_alphabet;
    size_t alphabet_index = 0;

    for(int grid_x=0; grid_x<cipher_grid.size(); ++grid_x) {
        for(int grid_y=0; grid_y<cipher_grid.at(0).size(); ++grid_y) {

            if(keyword_index < keyword.size()) {
                cipher_grid.at(grid_x).at(grid_y) = keyword.at(keyword_index++);
            } else {
                if(!stripped_alphabet.size()) {
                    // I and J share a slot, so J's are stripped in favor of I's.
                    std::copy_if(ALPHABET.begin(), ALPHABET.end(), std::back_inserter(stripped_alphabet), [&keyword](char character) -> bool {
                        return keyword.find(character) == std::string::npos && character != 'J';
                    });
                }

                cipher_grid.at(grid_x).at(grid_y) = stripped_alphabet.at(alphabet_index++);
                if(alphabet_index >= stripped_alphabet.size()) alphabet_index = 0;
            }
        }
    }

    // Display rendered cipher grid.
    for(int grid_x=0; grid_x<cipher_grid.size(); ++grid_x) {
        for(int grid_y=0; grid_y<cipher_grid.at(0).size(); ++grid_y) {
            std::cout << "|" << cipher_grid.at(grid_x).at(grid_y);
        }

        std::cout << "|" << std::endl;
    }


    RemoveSymmetricalDiagraphs(message);

    std::cout << "Desymmed message: " << message << std::endl;

    std::vector<std::pair<char, char>> diagraphs;

    for(int i=0; i<message.size(); ++i) {
        if((i % 2) != 0) {
            diagraphs.emplace_back(std::make_pair(message[i-1], message[i]));
        }
    }

    std::cout << "Diagraphs: ";

    for(const auto& pair : diagraphs) {
        std::cout << "[" << pair.first << "," << pair.second << "], ";
    }

    std::cout << std::endl;


    std::string result_text;


    for(auto& diagraph : diagraphs) {
        char& first = diagraph.first;
        char& second = diagraph.second;

        int first_row, first_column = 0;
        int second_row, second_column = 0;

        for(int grid_x=0; grid_x<cipher_grid.size(); ++grid_x) {
            for(int grid_y=0; grid_y<cipher_grid[0].size(); ++grid_y) {
                char& character = cipher_grid[grid_x][grid_y];

                if(character == first) {
                    first_row = grid_x;
                    first_column = grid_y;
                } else if(character == second) {
                    second_row = grid_x;
                    second_column = grid_y;
                }
            }
        }

        char first_ciphered, second_ciphered;

        if(!deciphering) {
            if(first_row == second_row){
                first_ciphered = cipher_grid[first_row][first_column+1 < cipher_grid[0].size() ? first_column+1 : 0];
                second_ciphered = cipher_grid[second_row][second_column+1 < cipher_grid[0].size() ? second_column+1 : 0];
            } else if(first_column == second_column) {
                first_ciphered = cipher_grid[first_row+1 < cipher_grid.size() ? first_row+1 : 0][first_column];
                second_ciphered = cipher_grid[second_row+1 < cipher_grid.size() ? second_row+1 : 0][second_column];
            } else {
                first_ciphered = cipher_grid[first_row][second_column];
                second_ciphered = cipher_grid[second_row][first_column];
            }
        } else {
            if(first_row == second_row) {
                first_ciphered = cipher_grid[first_row][first_column == 0 ? cipher_grid[first_row].size()-1 : first_column - 1];
                second_ciphered = cipher_grid[second_row][second_column == 0 ? cipher_grid[second_row].size()-1 : second_column - 1];
            } else if(first_column == second_column) {
                first_ciphered = cipher_grid[first_row == 0 ? cipher_grid.size() - 1 : first_row - 1][first_column];
                second_ciphered = cipher_grid[second_row == 0 ? cipher_grid.size() - 1 : second_row - 1][second_column];
            } else {
                first_ciphered = cipher_grid[first_row][second_column];
                second_ciphered = cipher_grid[second_row][first_column];
            }
        }

        result_text.push_back(first_ciphered);
        result_text.push_back(second_ciphered);
    }


    return result_text;
}
