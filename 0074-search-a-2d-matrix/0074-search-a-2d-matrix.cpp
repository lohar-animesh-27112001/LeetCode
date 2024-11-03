class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;

        int column = matrix[0].size();
        if(column == 0) return false;

        int i = 0;
        int j = row - 1;

        if(matrix[i][column - 1] == target || matrix[j][column - 1] == target ||
         matrix[i][0] == target || matrix[j][0] == target) {
            return true;
        }

        while((j - i) > 1) {
            int mid = (i + j) / 2;
            if(matrix[mid][column - 1] == target || matrix[mid][0] == target) {
                return true;
            }
            if(matrix[mid][column - 1] < target) {
                i = mid;
            } else {
                j = mid;
            }
        }

        if(matrix[i][column - 1] >= target) {
            row = i;
        } else {
            row = j;
        }
        cout << row << endl;

        i = 0;
        j = column - 1;

        while((j - i) > 1) {
            int mid = (i + j) / 2;
            if(matrix[row][mid] == target) {
                return true;
            }
            if(matrix[row][mid] < target) {
                i = mid;
            } else {
                j = mid;
            }
        }

        return matrix[row][i] == target || matrix[row][j] == target;
    }
};