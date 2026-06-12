 #pragma GCC optimize("O3")

#include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    int LOG;
    vector<int> depth;
    vector<vector<int>> up;
    vector<long long> powerOfTwo;

    // Precompute powers of 2 modulo 10^9 + 7
    void precomputePowers(int max_n) {
        powerOfTwo.resize(max_n + 1);
        powerOfTwo[0] = 1;
        for (int i = 1; i <= max_n; i++) {
            powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
        }
    }

    // DFS to compute depths and the first ancestor (2^0)
    void dfs(int node, int parent, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = parent;
        
        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }

    // Function to find LCA using Binary Lifting
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // Bring both nodes to the same depth
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        // Lift both nodes simultaneously
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    // Notice the signature now exactly matches what LeetCode expects: just edges and queries
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // Calculate n based on the number of edges (a tree has n - 1 edges)
        int n = edges.size() + 1;
        
        LOG = ceil(log2(n)) + 1;
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));
        
        precomputePowers(n);

        // Build adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Run DFS starting from root node 1
        dfs(1, -1, 0, adj);

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int lca = getLCA(u, v);
            int k = depth[u] + depth[v] - 2 * depth[lca];

            // Number of ways is 2^(k-1) % MOD
            answer.push_back(powerOfTwo[k - 1]);
        }

        return answer;
    }
};