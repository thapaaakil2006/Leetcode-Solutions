#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
    // Structure to store subarray data in the Max-Heap
    struct Element {
        long long val;
        int l;
        int r;
        
        bool operator<(const Element& other) const {
            return val < other.val; // Sort to create a Max-Heap based on val
        }
    };

    // Sparse Table for O(1) Range Maximum and Minimum Queries (RMQ)
    class SparseTable {
        int n;
        int maxLog;
        vector<vector<int>> maxTable;
        vector<vector<int>> minTable;
        vector<int> logTable;

    public:
        SparseTable(const vector<int>& arr) {
            n = arr.size();
            logTable.resize(n + 1);
            logTable[1] = 0;
            for (int i = 2; i <= n; i++) {
                logTable[i] = logTable[i / 2] + 1;
            }
            
            maxLog = logTable[n] + 1;
            maxTable.assign(n, vector<int>(maxLog));
            minTable.assign(n, vector<int>(maxLog));
            
            // Initialize base cases for intervals of length 1
            for (int i = 0; i < n; i++) {
                maxTable[i][0] = arr[i];
                minTable[i][0] = arr[i];
            }
            
            // Build the table using dynamic programming
            for (int j = 1; j < maxLog; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    maxTable[i][j] = max(maxTable[i][j - 1], maxTable[i + (1 << (j - 1))][j - 1]);
                    minTable[i][j] = min(minTable[i][j - 1], minTable[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
        
        long long queryMax(int l, int r) {
            int length = r - l + 1;
            int k = logTable[length];
            return max(maxTable[l][k], maxTable[r - (1 << k) + 1][k]);
        }
        
        long long queryMin(int l, int r) {
            int length = r - l + 1;
            int k = logTable[length];
            return min(minTable[l][k], minTable[r - (1 << k) + 1][k]);
        }
        
        long long queryVal(int l, int r) {
            return queryMax(l, r) - queryMin(l, r);
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st(nums);
        priority_queue<Element> pq;
        
        // Push the absolute best right-boundary configuration for every starting index l
        for (int l = 0; l < n; l++) {
            pq.push({st.queryVal(l, n - 1), l, n - 1});
        }
        
        long long totalValue = 0;
        
        // Greedily extract the top k unique subarray values
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            Element curr = pq.top();
            pq.pop();
            
            totalValue += curr.val;
            
            // If the right pointer can be shrunk closer to l, push the next best candidate
            if (curr.r > curr.l) {
                pq.push({st.queryVal(curr.l, curr.r - 1), curr.l, curr.r - 1});
            }
        }
        
        return totalValue;
    }
};