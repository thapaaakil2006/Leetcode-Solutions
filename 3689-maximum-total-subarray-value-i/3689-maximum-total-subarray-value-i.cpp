#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxTotalValue(std::vector<int>& nums, int k) {
        // Find the maximum and minimum elements in the array
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        
        long long max_val = *max_it;
        long long min_val = *min_it;
        
        // Calculate the maximum value for a single optimal subarray
        long long single_subarray_max = max_val - min_val;
        
        // Multiply by k to get the total maximum value
        return single_subarray_max * k;
    }
};