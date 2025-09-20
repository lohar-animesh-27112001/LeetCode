class Solution {
private:
    int n;
    vector<vector<int>> dp;

    int maxProfit(int i, int tranNo, vector<int>& prices, int k) {
        if (i == n || tranNo == 2 * k) return 0;
        if (dp[i][tranNo] != -1) return dp[i][tranNo];

        if (tranNo % 2 == 0) {
            int buy = -prices[i] + maxProfit(i + 1, tranNo + 1, prices, k);
            int skip = maxProfit(i + 1, tranNo, prices, k);
            return dp[i][tranNo] = max(buy, skip);
        } else {
            int sell = prices[i] + maxProfit(i + 1, tranNo + 1, prices, k);
            int skip = maxProfit(i + 1, tranNo, prices, k);
            return dp[i][tranNo] = max(sell, skip);
        }
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2 * k, -1));
        return maxProfit(0, 0, prices, k);
    }
};
