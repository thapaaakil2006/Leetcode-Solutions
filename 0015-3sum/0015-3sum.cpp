#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // 1. Sort the array
        std::sort(nums.begin(), nums.end());
        
        // 2. Iterate through the array fixing the first element
        for (int i = 0; i < n - 2; i++) {
            // Optimization: If the smallest number is greater than 0, 
            // no three numbers can sum up to 0.
            if (nums[i] > 0) break;
            
            // Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 3. Two-pointer approach for the remaining two elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Need a larger value
                } 
                else {
                    right--; // Need a smaller value
                }
            }
        }
        
        return result;
    }
};