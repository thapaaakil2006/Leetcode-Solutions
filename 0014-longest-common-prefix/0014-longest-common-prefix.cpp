#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        
        // Sort the strings lexicographically
        std::sort(strs.begin(), strs.end());
        
        // Compare the first and last strings
        std::string first = strs[0];
        std::string last = strs[strs.size() - 1];
        std::string result = "";
        
        for (int i = 0; i < first.length(); i++) {
            // If characters match, add to result; otherwise, stop
            if (first[i] == last[i]) {
                result += first[i];
            } else {
                break;
            }
        }
        
        return result;
    }
};