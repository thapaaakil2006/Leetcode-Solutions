#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Vector to store the last seen index of each character.
        // Initialize all elements to -1 (meaning not seen yet).
        // Using 128 covers all standard ASCII characters.
        std::vector<int> lastSeen(128, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); right++) {
            char current_char = s[right];
            
            // If the character was seen before AND its last occurrence 
            // is inside our current window, move 'left' past that occurrence.
            if (lastSeen[current_char] >= left) {
                left = lastSeen[current_char] + 1;
            }
            
            // Update the last seen position of the character
            lastSeen[current_char] = right;
            
            // Calculate current window length and update maxLength
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};