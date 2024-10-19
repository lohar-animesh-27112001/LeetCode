class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows < 1) {
            return ans;
        }
        if(numRows >= 1) {
            ans.push_back({1});
            if(numRows == 1) {
                return ans;
            }
        }
        if(numRows >= 2) {
            ans.push_back({1, 1});
            if(numRows == 2) {
                return ans;
            }
        }
        for(int i = 1; i < numRows - 1; i++) {
            vector<int> v;
            v.push_back(1);
            for(int j = 1; j <= i; j++) {
                int temp = ans[i][j] + ans[i][j-1];
                v.push_back(temp);
            }
            v.push_back(1);
            ans.push_back({v});
        }
        return ans;
    }
};