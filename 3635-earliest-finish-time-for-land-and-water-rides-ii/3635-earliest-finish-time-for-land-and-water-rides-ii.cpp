#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    struct Ride {
        int start;
        int duration;
        int finish;
    };

    long long solveOneDirection(const vector<int>& startA, const vector<int>& durationA, const vector<int>& startB, const vector<int>& durationB) {
        int n = startA.size();
        int m = startB.size();

        // 1. Structure and sort the second category (B) by start times
        vector<Ride> ridesB(m);
        for (int i = 0; i < m; ++i) {
            ridesB[i] = {startB[i], durationB[i], startB[i] + durationB[i]};
        }
        sort(ridesB.begin(), ridesB.end(), [](const Ride& a, const Ride& b) {
            return a.start < b.start;
        });

        // 2. Precompute prefix minimums of B's durations
        vector<int> prefMinDuration(m);
        prefMinDuration[0] = ridesB[0].duration;
        for (int i = 1; i < m; ++i) {
            prefMinDuration[i] = min(prefMinDuration[i - 1], ridesB[i].duration);
        }

        // 3. Precompute suffix minimums of B's individual finish times
        vector<int> suffMinFinish(m);
        suffMinFinish[m - 1] = ridesB[m - 1].finish;
        for (int i = m - 2; i >= 0; --i) {
            suffMinFinish[i] = min(suffMinFinish[i + 1], ridesB[i].finish);
        }

        long long minTotalFinish = LLONG_MAX;

        // 4. Iterate through every ride in category A
        for (int i = 0; i < n; ++i) {
            long long finishA = (long long)startA[i] + durationA[i];

            // Binary search to find the partition point where rideB.start > finishA
            int low = 0, high = m - 1;
            int idx = m; // Default if all rides start <= finishA

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (ridesB[mid].start > finishA) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Case 1: Ride B can be boarded immediately upon finishing Ride A (startB <= finishA)
            // We look at the prefix [0 ... idx - 1]
            if (idx > 0) {
                long long currentFinish = finishA + prefMinDuration[idx - 1];
                minTotalFinish = min(minTotalFinish, currentFinish);
            }

            // Case 2: Ride B opens after Ride A finishes (startB > finishA)
            // We look at the suffix [idx ... m - 1]
            if (idx < m) {
                long long currentFinish = suffMinFinish[idx];
                minTotalFinish = min(minTotalFinish, currentFinish);
            }
        }

        return minTotalFinish;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // Run direction 1: Land -> Water
        long long landThenWater = solveOneDirection(landStartTime, landDuration, waterStartTime, waterDuration);
        
        // Run direction 2: Water -> Land
        long long waterThenLand = solveOneDirection(waterStartTime, waterDuration, landStartTime, landDuration);
        
        return min(landThenWater, waterThenLand);
    }
};