#include <vector>
#include <algorithm>

class Solution {
private:
    const int MOD = 1e9 + 7;

    // Helper function for fast modular exponentiation: (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // DFS to find the maximum depth (number of edges from root)
    void dfs(int node, int parent, int depth, int& max_depth, const std::vector<std::vector<int>>& adj) {
        max_depth = std::max(max_depth, depth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, max_depth, adj);
            }
        }
    }

public:
    // Fixed method signature to match LeetCode's expectations
    int assignEdgeWeights(std::vector<std::vector<int>>& edges) {
        int n = edges.size() + 1; // Number of nodes is always edges + 1 in a valid tree
        
        // Step 1: Build the adjacency list for the tree
        std::vector<std::vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Find the maximum depth starting from root node 1
        int max_depth = 0;
        dfs(1, 0, 0, max_depth, adj);

        // Step 3: Calculate 2^(max_depth - 1) % MOD
        if (max_depth == 0) return 0;
        
        return power(2, max_depth - 1);
    }
};