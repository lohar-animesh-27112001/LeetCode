#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        if (grid[0][0] == -1) 
            return 0;

        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0] = grid[0][0];

        for (int step = 1; step <= 2*n-2; step++) {
            vector<vector<int>> new_dp(n, vector<int>(n, INT_MIN));

            for (int r1 = max(0, step - (n-1)); r1 <= min(n-1, step); r1++) {
                int c1 = step - r1;
                if (c1 < 0 || c1 >= n) continue;
                if (grid[r1][c1] == -1) continue;

                for (int r2 = max(0, step - (n-1)); r2 <= min(n-1, step); r2++) {
                    int c2 = step - r2;
                    if (c2 < 0 || c2 >= n) continue;
                    if (grid[r2][c2] == -1) continue;

                    int best_prev = INT_MIN;
                    if (r1-1 >= 0 && r2-1 >= 0) 
                        best_prev = max(best_prev, dp[r1-1][r2-1]);
                    if (r1-1 >= 0) 
                        best_prev = max(best_prev, dp[r1-1][r2]);
                    if (r2-1 >= 0) 
                        best_prev = max(best_prev, dp[r1][r2-1]);
                    best_prev = max(best_prev, dp[r1][r2]);

                    if (best_prev == INT_MIN) continue;

                    if (r1 == r2)
                        new_dp[r1][r2] = best_prev + grid[r1][c1];
                    else
                        new_dp[r1][r2] = best_prev + grid[r1][c1] + grid[r2][c2];
                }
            }
            dp = new_dp;
        }

        return dp[n-1][n-1] == INT_MIN ? 0 : dp[n-1][n-1];
    }
};