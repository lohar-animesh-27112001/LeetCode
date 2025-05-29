class Solution {
private:
    int m = 0, n = 0;
    int totalSteps = 0;
    int ans = 0;
    void searchIndex(vector<vector<int>>& v, int &x, int &y, int target) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(v[i][j] == target) {
                    x = i;
                    y = j;
                }
            }
        }
    }
    void uniquePaths(int i, int j, int stepsRemaining,
                     vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return;
        if(grid[i][j] == 2) {
            if(stepsRemaining == 0) ans++;
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        uniquePaths(i+1, j, stepsRemaining - 1, grid);
        uniquePaths(i-1, j, stepsRemaining - 1, grid);
        uniquePaths(i, j+1, stepsRemaining - 1, grid);
        uniquePaths(i, j-1, stepsRemaining - 1, grid);
        grid[i][j] = temp;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int startX = 0, startY = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] != -1)
                    totalSteps += 1;
        searchIndex(grid, startX, startY, 1);
        uniquePaths(startX, startY, totalSteps - 1, grid);
        return ans;
    }
};