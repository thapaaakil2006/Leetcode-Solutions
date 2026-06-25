#include <vector>

class Solution {
public:
    int countMajoritySubarrays(std::vector<int>& nums, int target) {
        int totalSubarrays = 0;
        int n = nums.size();
        
        // Check every possible starting point for a subarray
        for (int i = 0; i < n; i++) {
            int targetCount = 0;
            
            // Expand the subarray ending at j
            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    targetCount++;
                }
                
                int currentLength = j - i + 1;
                
                // A target is a strict majority if its count is greater than half the length
                if (targetCount * 2 > currentLength) {
                    totalSubarrays++;
                }
            }
        }
        
        return totalSubarrays;
    }
};