class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        for(int j = column - 2; j >= 0; j--) {
            for(int i = 0; i < row; i++) {
                if(grid[i][j+1] > grid[i][j]) {
                    dp[i][j] = 1 + dp[i][j+1];
                }
                if(i > 0 && grid[i - 1][j + 1] > grid[i][j]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j + 1]);
                }
                if(i < row - 1 && grid[i + 1][j + 1] > grid[i][j]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < row; i++) {
            answer = max(answer, dp[i][0]);
        }
        return answer;
    }
};