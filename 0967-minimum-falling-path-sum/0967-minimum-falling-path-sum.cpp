class Solution {
private:
    int n = 0;
    int minFallingPathSum(vector<vector<int>>& v, int row, int col, 
                            vector<vector<int>> &dp) {
        if(col >= n || col < 0) return INT_MAX;
        if(dp[row][col] != INT_MAX) return dp[row][col];
        if(row == n-1) {
            dp[row][col] = v[row][col];
            return dp[row][col];
        }
        dp[row][col] = v[row][col] + min(
            minFallingPathSum(v,row+1,col+1,dp), min(
            minFallingPathSum(v,row+1,col,dp),
            minFallingPathSum(v,row+1,col-1,dp)));
        return dp[row][col];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        int minSum = INT_MAX;
        vector<vector<int>> mem(n, vector<int>(n,INT_MAX));
        for(int i = 0; i < n; i++) {
            minSum = min(minSum, minFallingPathSum(matrix,0,i,mem));
        }
        return minSum;
    }
};