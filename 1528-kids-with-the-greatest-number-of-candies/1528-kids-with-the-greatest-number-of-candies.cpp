class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(candies.size(), false);
        int max_element = INT_MIN;
        for(int i : candies)
            if(i > max_element)
                max_element = i;
        for(int i = 0; i < n; i++)
            if(candies[i] + extraCandies >= max_element)
                ans[i] = true;
        return ans;
    }
};