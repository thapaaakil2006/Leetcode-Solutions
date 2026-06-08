#include <vector>

class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
        std::vector<int> result;
        result.reserve(nums.size()); // Optimize memory allocation
        
        // Pass 1: Add all elements smaller than the pivot
        for (int num : nums) {
            if (num < pivot) {
                result.push_back(num);
            }
        }
        
        // Pass 2: Add all elements equal to the pivot
        for (int num : nums) {
            if (num == pivot) {
                result.push_back(num);
            }
        }
        
        // Pass 3: Add all elements greater than the pivot
        for (int num : nums) {
            if (num > pivot) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};