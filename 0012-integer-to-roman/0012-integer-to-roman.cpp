#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Pairs of values and their corresponding Roman numeral representations
        const std::vector<std::pair<int, std::string>> romanMapping = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        std::string result = "";
        
        for (const auto& mapping : romanMapping) {
            // While the number is large enough, append the symbol and subtract the value
            while (num >= mapping.first) {
                result += mapping.second;
                num -= mapping.first;
            }
        }
        
        return result;
    }
};