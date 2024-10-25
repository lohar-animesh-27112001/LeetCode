class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zero_index;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    zero_index.push_back({i, j});
                }
            }
        }
        for(pair<int, int> index : zero_index) {
            int row = index.first;
            int col = index.second;
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[row][j] = 0;
            }
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
