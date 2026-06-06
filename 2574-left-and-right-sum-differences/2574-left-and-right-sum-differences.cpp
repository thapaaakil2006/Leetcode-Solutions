#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n);
        
        // Calculate the total sum of the array
        int rightSum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        
        for (int i = 0; i < n; ++i) {
            // rightSum for index i is total remaining sum minus the current element
            rightSum -= nums[i];
            
            // Store the absolute difference
            answer[i] = std::abs(leftSum - rightSum);
            
            // Update leftSum to include the current element for the next index
            leftSum += nums[i];
        }
        
        return answer;
    }
};