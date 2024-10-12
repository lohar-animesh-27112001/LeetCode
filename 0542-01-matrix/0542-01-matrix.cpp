class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); // Number of rows
        int m = mat[0].size(); // Number of columns
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int visit = q.front().second;
            distance[row][col] = visit;
            if((row + 1) < n && visited[row + 1][col] == 0) {
                visited[row + 1][col] = 1;
                q.push({{row + 1, col}, visit + 1});
            }
            if((row - 1) >= 0 && visited[row - 1][col] == 0) {
                visited[row - 1][col] = 1;
                q.push({{row - 1, col}, visit + 1});
            }
            if((col + 1) < m && visited[row][col + 1] == 0) {
                visited[row][col + 1] = 1;
                q.push({{row, col + 1}, visit + 1});
            }
            if((col - 1) >= 0 && visited[row][col - 1] == 0) {
                visited[row][col - 1] = 1;
                q.push({{row, col - 1}, visit + 1});
            }
            q.pop();
        }
        return distance;
    }
};