class Solution {
private:
    int maxProf(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int buy = prices[0];
        int profit = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] >= prices[i - 1])
                continue;
            else {
                profit += prices[i - 1] - buy;
                buy = prices[i];
            }
            cout << profit << " ";
        }
        if(prices[n - 1] > buy)
            profit += prices[n - 1] - buy;
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0;
        int hold = INT_MIN;
        for(auto price : prices) {
            if(sell < hold + price) {
                sell = hold + price;
            }
            if(hold < - price) {
                hold = - price;
            }
        }
        
        return sell;
    }
};