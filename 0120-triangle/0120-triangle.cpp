class Solution {
private:
    int n = 0;
    void minimumTotal(vector<vector<int>>& arr, int i, int curr,
                        vector<vector<int>>& dp) {
        if(i >= n) return;
        if(i == n-1) {
            dp[i][curr] = arr[i][curr];
            return;
        }
        if(dp[i][curr] != -1) return;
        minimumTotal(arr,i+1,curr,dp);
        minimumTotal(arr,i+1,curr+1,dp);
        dp[i][curr] = arr[i][curr] + min(dp[i+1][curr], dp[i+1][curr+1]);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        vector<vector<int>> mem(n, vector<int>(n,-1));
        minimumTotal(triangle,0,0,mem);
        return mem[0][0];
    }
};