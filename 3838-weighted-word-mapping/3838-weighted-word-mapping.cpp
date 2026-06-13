#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        // Process each word in the array
        for (const string& word : words) {
            int sum = 0;
            
            // Calculate the total weight of the current word
            for (char c : word) {
                sum += weights[c - 'a'];
            }
            
            // Take the sum modulo 26
            int modVal = sum % 26;
            
            // Map to a character using reverse alphabetical order
            // 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            char mappedChar = 'z' - modVal;
            
            // Append the character to the result string
            result += mappedChar;
        }
        
        return result;
    }
};