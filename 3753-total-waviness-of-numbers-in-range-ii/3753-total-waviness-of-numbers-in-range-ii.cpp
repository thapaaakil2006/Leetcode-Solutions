#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// dp[pos][tight][is_leading][last][second_last]
// Storing a pair: {count_of_valid_numbers, sum_of_waviness}
pair<long long, long long> dp[16][2][2][11][11]; 
bool visited[16][2][2][11][11];

class Solution {
private:
    string num_str;

    pair<long long, long long> dfs(int pos, bool tight, bool is_leading, int last, int second_last) {
        // Base case: placed all digits
        if (pos == num_str.length()) {
            return {1, 0}; // Found 1 valid number, its suffix contribution to waviness is 0
        }

        if (visited[pos][tight][is_leading][last][second_last]) {
            return dp[pos][tight][is_leading][last][second_last];
        }

        long long total_count = 0;
        long long total_waviness = 0;
        int limit = tight ? (num_str[pos] - '0') : 9;

        for (int d = 0; d <= limit; ++d) {
            bool next_tight = tight && (d == limit);
            bool next_leading = is_leading && (d == 0);

            // Determine if the 'last' digit forms a peak or valley
            int waviness_contribution = 0;
            if (!is_leading && last != 10 && second_last != 10) {
                if ((last > second_last && last > d) || (last < second_last && last < d)) {
                    waviness_contribution = 1;
                }
            }

            // Transition to the next digit position
            // If the next state is still leading zero, track 'last' and 'second_last' as dummy values (10)
            int next_last = next_leading ? 10 : d;
            int next_second_last = next_leading ? 10 : last;

            auto [sub_count, sub_waviness] = dfs(pos + 1, next_tight, next_leading, next_last, next_second_last);

            total_count += sub_count;
            // Total waviness = waviness from subsequent digits + (contribution of 'last' * number of variations it applies to)
            total_waviness += sub_waviness + (waviness_contribution * sub_count);
        }

        visited[pos][tight][is_leading][last][second_last] = true;
        return dp[pos][tight][is_leading][last][second_last] = {total_count, total_waviness};
    }

    long long countWaviness(long long n) {
        if (n < 100) return 0; // Any number with fewer than 3 digits has a waviness of 0
        
        num_str = to_string(n);
        memset(visited, false, sizeof(visited));
        
        // Start from position 0, tight=true, is_leading=true, last=10 (dummy), second_last=10 (dummy)
        return dfs(0, true, true, 10, 10).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return countWaviness(num2) - countWaviness(num1 - 1);
    }
};