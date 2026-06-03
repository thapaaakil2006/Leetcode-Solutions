#include <string>
#include <algorithm>

class Solution {
private:
    // Helper function to expand around the center and return the length of the palindrome
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Returns the length of the palindrome found
        // Formula: (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0; // Tracks the start index of the longest palindrome
        int maxLength = 0; // Tracks the maximum length found
        
        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindrome (e.g., "aba", center is 'b')
            int len1 = expandAroundCenter(s, i, i);
            
            // Case 2: Even length palindrome (e.g., "abba", center is between 'b' and 'b')
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get the maximum length between the two cases
            int len = std::max(len1, len2);
            
            // If we found a longer palindrome, update our boundaries
            if (len > maxLength) {
                maxLength = len;
                // Calculate the starting position of the substring
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
};