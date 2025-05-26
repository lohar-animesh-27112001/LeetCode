class Solution {
private:
    int n = 0;
    void rob(vector<int>& v, int i, vector<int> &dp) {
        if(i >= n) return;
        if(dp[i] != -1) return;
        if(i == n-1 || i == n-2) {
            dp[i] = v[i];
            return;
        }
        rob(v, i+2, dp);
        rob(v, i+3, dp);
        if(i == n-3) {
            dp[i] = dp[i] + dp[i+2];
        }
        dp[i] = max(v[i] + dp[i+2], v[i] + dp[i+3]);
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> mem(n+1, -1);
        rob(nums, 0, mem);
        rob(nums, 1, mem);
        return max(mem[0], mem[1]);
    }
};