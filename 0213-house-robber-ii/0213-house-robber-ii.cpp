class Solution {
private:
    void rob(vector<int>& v, int i, vector<int> &dp, int n) {
        if(i >= n) return;
        if(dp[i] != -1) return;
        if(i == n-1 || i == n-2) {
            dp[i] = v[i];
            return;
        }
        rob(v, i+2, dp, n);
        rob(v, i+3, dp, n);
        if(i == n-3)
            dp[i] = dp[i] + dp[i+2];
        dp[i] = max(v[i] + dp[i+2], v[i] + dp[i+3]);
    }
public:
    int rob(vector<int>& nums) {
        int range = nums.size();
        if(range == 1) return nums[0];
        if(range == 3) return max(nums[0],max(nums[1],nums[2]));
        vector<int> mem1(range+1, -1);
        vector<int> mem2(range+1, -1);
        vector<int> mem3(range+1, -1);
        rob(nums, 0, mem1, range - 1);
        rob(nums, 1, mem2, range);
        rob(nums, 2, mem3, range);
        // for(auto i:mem1) cout << i << " ";
        // cout << endl;
        // for(auto i:mem2) cout << i << " ";
        return max(mem1[0], max(mem2[1], mem3[2]));
    }
};