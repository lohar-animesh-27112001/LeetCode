class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int hold = INT_MIN;
        for(const int price : prices) {
            profit = max(profit, hold + price);
            hold = max(hold, profit - price);
        }
        return profit;
    }
};