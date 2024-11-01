class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n * n + 1, 0);
        vector<int> ans(2);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                v[grid[i][j]]++;
            }
        }
        
        for(int i = 1; i <= n * n; i++) {
            if(v[i] == 2) {
                ans[0] = i;
            }
            if(v[i] == 0) {
                ans[1] = i;
            }
        }
        
        return ans;
    }
};