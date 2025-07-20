class Solution {
private:
    int num = 0;
    // int maxProf(vector<int>& prices) {
    //     int n = prices.size();
    //     if(n <= 1) return 0;
    //     int f = INT_MIN, s = INT_MIN, buy = prices[0];
    //     for(int i = 1; i < n; i++) {
    //         if(prices[i] >= prices[i-1]) continue;
    //         else {
    //             int prof = prices[i-1] - buy;
    //             if(prof > f) {
    //                 int temp = f;
    //                 f = prof;
    //                 s = temp;
    //             } else if(prof > s) {
    //                 s = prof;
    //             }
    //             buy = prices[i];
    //         }
    //     }
    //     if(prices[n-1] >= prices[n-2]) {
    //         int prof = prices[n-1] - buy;
    //         if(prof > f) {
    //             int temp = f;
    //             f = prof;
    //             s = temp;
    //         } else if(prof > s) {
    //             s = prof;
    //         }
    //     }
    //     s = (s == INT_MIN ? 0 : s);
    //     f = max(0, f);
    //     return s + f;
    // }
    int profit(vector<int>& prices, int &index) {
        int sell = 0, hold = INT_MIN, p = 0;
        for(int i = 0; i < index; i++){
            if(sell < hold + prices[i])
                sell = hold + prices[i];
            if(hold < - prices[i])
                hold = - prices[i];
        }
        p = sell, sell = 0, hold = INT_MIN;
        for(int i = index; i < num; i++){
            if(sell < hold + prices[i])
                sell = hold + prices[i];
            if(hold < - prices[i])
                hold = - prices[i];
        }
        return p + sell;
    }
    int finalMaxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int min_price = prices[0];
        for(int i = 1; i < n; ++i){
            min_price = min(min_price, prices[i]);
            left[i] = max(left[i-1], prices[i] - min_price);
        }
        int max_price = prices[n-1];
        for(int i = n-2; i >= 0; --i){
            max_price = max(max_price, prices[i]);
            right[i] = max(right[i+1], max_price - prices[i]);
        }
        int max_profit = 0;
        for(int i = 0; i < n; ++i){
            max_profit = max(max_profit, left[i] + right[i]);
        }
        return max_profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = INT_MIN;
        num = prices.size();
        if(num <= 1) return 0;
        // for(int i = 0; i < num; i++) {
        //     maxprof = max(maxprof, profit(prices, i));
        // }
        return finalMaxProfit(prices);
    }
};