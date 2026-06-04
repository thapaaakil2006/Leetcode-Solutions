#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        
        for (int i = num1; i <= num2; ++i) {
            // Numbers with fewer than 3 digits have a waviness of 0
            if (i < 100) continue;
            
            // Convert to string to easily inspect neighbors
            std::string s = std::to_string(i);
            int n = s.length();
            
            // First and last digits cannot be peaks or valleys
            for (int j = 1; j < n - 1; ++j) {
                if (s[j] > s[j - 1] && s[j] > s[j + 1]) {
                    // It's a peak
                    total_sum++;
                } else if (s[j] < s[j - 1] && s[j] < s[j + 1]) {
                    // It's a valley
                    total_sum++;
                }
            }
        }
        
        return total_sum;
    }
};