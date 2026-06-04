#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    // Mapping of digits 2-9 to their corresponding letters
    const std::vector<std::string> phoneMap = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        // Base case: if the current combination is complete
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters that the current digit maps to
        std::string letters = phoneMap[digits[index] - '0'];
        
        for (char letter : letters) {
            current.push_back(letter);          // Make a choice
            backtrack(digits, index + 1, current, result); // Recurse for the next digit
            current.pop_back();                 // Backtrack (undo the choice)
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        
        // Edge case: if the input is empty
        if (digits.empty()) {
            return result;
        }

        std::string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};