class Solution {
private:
    int n = 0;
    int final_count = INT_MAX;
    vector<int> dp;
    long long coinChange(vector<int>& coins, int amount, long long sum, long long count) {
        if (sum > amount) return LLONG_MAX;
        if (sum == amount) {
            final_count = min(final_count, (int)count);
            return count;
        }
        if (dp[sum] != -1 && dp[sum] <= count) return LLONG_MAX;
        dp[sum] = count;
        long long min_count = LLONG_MAX;
        for (int coin : coins) {
            long long res = coinChange(coins, amount, sum + coin, count + 1);
            min_count = min(min_count, res);
        }
        return min_count;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        n = coins.size();
        dp.resize(amount + 1, -1);
        coinChange(coins, amount, 0, 0);
        return final_count == INT_MAX ? -1 : final_count;
    }
};
