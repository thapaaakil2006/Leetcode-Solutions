#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge case: If only 1 row or string is too short, no zigzag happens
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        
        // Create an array of strings for each row
        std::vector<std::string> rows(std::min(numRows, (int)s.length()));
        
        int currentRow = 0;
        bool goingDown = false;
        
        // Distribute characters into their respective rows
        for (char c : s) {
            rows[currentRow] += c;
            
            // Turn around if we hit the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down
            currentRow += goingDown ? 1 : -1;
        }
        
        // Combine all rows into a single string
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }
        
        return result;
    }
};