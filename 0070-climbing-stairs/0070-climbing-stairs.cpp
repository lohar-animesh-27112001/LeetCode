class Solution {
private:
    void climbStairs(int n, int &ans) { // Only Recursion
        if(n == 0 || n == 1) {
            return;
        }
        ans++;
        climbStairs(n-1, ans);
        climbStairs(n-2, ans);
    }
    void climbStairs(int n, vector<int> &dp) { // Recursion + DP
        if(n == 2 || n == 1) {
            dp[n] = n;
            return;
        }
        if(dp[n] != -1) return;
        climbStairs(n-1, dp);
        climbStairs(n-2, dp);
        dp[n] = dp[n-1] + dp[n-2];
    }
public:
    int climbStairs(int n) {
        int ans = 1;
        // climbStairs(n, ans);
        vector<int> mem(n+1, -1);
        climbStairs(n, mem);
        cout << mem[n];
        return mem[n];
    }
};