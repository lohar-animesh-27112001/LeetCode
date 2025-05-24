class Solution {
private:
    int fib(int n, vector<int> &dp) { // DP + Recursiom
        if(n == 0 || n == 1) {
            dp[n] = n;
            return n;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1, dp) + fib(n-2, dp);
    }
public:
    int fib(int n) {
        // vector<int> memory(n+1, -1);
        // return fib(n, memory);
        // Tablulation Approach
        if(n == 0 || n == 1) return n;
        int first = 0;
        int second = 1;
        for(int i = 2; i <= n; i++) {
            int num = first + second;
            first = second;
            second = num;
        }
        return second;
    }
};