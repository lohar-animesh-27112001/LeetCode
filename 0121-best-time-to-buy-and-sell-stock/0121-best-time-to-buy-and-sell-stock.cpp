class Solution {
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