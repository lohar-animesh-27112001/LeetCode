class Solution {
private:
    void uniquePaths(int &m, int &n, int i, int j,
                    vector<vector<int>> &dp,
                    vector<vector<int>>& arr) {
        if(i>=m || j>=n) return;
        if(arr[i][j] == 1) {
            dp[i][j] = 0;
            return;
        }
        if(m-1 == i && n-1 == j) {
            dp[i][j] = 1;
            return;
        }
        if(dp[i][j] != -1) return;
        uniquePaths(m,n,i+1,j,dp,arr);
        uniquePaths(m,n,i,j+1,dp,arr);
        dp[i][j] = ((i+1<m) ? dp[i+1][j] : 0) + 
                   ((j+1<n) ? dp[i][j+1] : 0);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> mem(m+1, vector<int>(n+1,-1));
        uniquePaths(m,n,0,0,mem,obstacleGrid);
        return mem[0][0];
    }
};