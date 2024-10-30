class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int column = matrix.size();
        int row = matrix[0].size();
        vector<vector<int>> answer(row, vector<int>(column));
        for(int i = 0; i < row; i++) {
            vector<int> v;
            for(int j = column - 1; j >=0; j--) {
                v.push_back(matrix[j][i]);
            }
            answer[i] = v;
        }
        matrix = answer;
    }
};