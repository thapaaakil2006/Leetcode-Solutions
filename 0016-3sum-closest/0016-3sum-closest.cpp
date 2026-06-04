#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to use the two-pointer approach
        std::sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first possible triplet
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If we find an exact match, return it immediately
                if (currentSum == target) {
                    return currentSum;
                }
                
                // If the current triplet sum is closer to the target, update closestSum
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on comparison with the target
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};