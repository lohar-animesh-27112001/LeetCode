class Solution {
private:
    int fib(int n, vector<int> &dp) {
        if(n == 0 || n == 1) {
            dp[n] = n;
            return n;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1, dp) + fib(n-2, dp);
    }
public:
    int fib(int n) {
        vector<int> memory(n+1, -1);
        return fib(n, memory);
    }
};