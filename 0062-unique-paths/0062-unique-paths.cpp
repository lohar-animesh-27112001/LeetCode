class Solution {
private:
    void uniquePaths(int &m, int &n, int &ans, int i, int j,
                    vector<vector<int>> &dp) {
        if(m-1 == i && n-1 == j) {
            dp[i][j] = 1;
            return;
        }
        if(i>=m || j>=n) return;
        if(dp[i][j] != -1) return;
        uniquePaths(m,n,ans,i+1,j,dp);
        uniquePaths(m,n,ans,i,j+1,dp);
        dp[i][j] = ((i+1<m) ? dp[i+1][j] : 0) + 
                   ((j+1<n) ? dp[i][j+1] : 0);
    }
public:
    int uniquePaths(int m, int n) {
        int uPaths = 0;
        vector<vector<int>> mem(m, vector<int>(n,-1));
        uniquePaths(m,n,uPaths,0,0,mem);
        return mem[0][0];
    }
};