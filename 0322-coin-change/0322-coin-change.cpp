class Solution {
private:
    int n = 0;
    int final_count = INT_MAX;
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount, 
                    long long sum, int count) {
        if (sum > amount) return INT_MAX;
        if (sum == amount) {
            final_count = min(final_count, (int)count);
            return count;
        }
        if (dp[sum] != -1 && dp[sum] <= count) return INT_MAX;
        dp[sum] = count;
        int min_count = INT_MAX;
        for (int coin : coins) {
            int res = coinChange(coins, amount, sum + coin, count + 1);
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
