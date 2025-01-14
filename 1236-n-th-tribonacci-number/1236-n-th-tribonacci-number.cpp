class Solution {
public:
    int tribonacci(int n) {
        vector<int> memo(n + 1, -1);
        return helper(n, memo);
    }
// Dynamic programming or memoization
private:
    int helper(int n, vector<int>& memo) {
        if (memo[n] != -1) return memo[n];
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        return memo[n] = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3,
                                memo);
    }
};
