#include <string>
#include <algorithm>

class Solution {
public:
    // Renamed from processString to processStr to match LeetCode's expected signature
    std::string processStr(std::string s) {
        std::string result = "";
        
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                // If it's a lowercase letter, append it
                result.push_back(c);
            } else if (c == '*') {
                // If it's '*', remove the last character (check if empty first!)
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                // If it's '#', duplicate the current result
                result += result;
            } else if (c == '%') {
                // If it's '%', reverse the current result
                std::reverse(result.begin(), result.end());
            }
        }
        
        return result;
    }
};