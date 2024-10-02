class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;
        bfs(image, initialColor, sr, sc, color);
        return image;
    }

    void bfs(vector<vector<int>>& image, int initialColor, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int first = p.first, second = p.second;
            image[first][second] = color;
            if(first + 1 >= 0 && first + 1 < image.size() && image[first + 1][second] == initialColor) {
                q.push({first + 1, second});
            }
            if(first - 1 >= 0 && first - 1 < image.size() && image[first - 1][second] == initialColor) {
                q.push({first - 1, second});
            }
            if(second + 1 >= 0 && second < image[0].size() && image[first][second + 1] == initialColor) {
                q.push({first, second + 1});
            }
            if(second - 1 >= 0 && second < image[0].size() && image[first][second - 1] == initialColor) {
                q.push({first, second - 1});
            }
        }
    }

    void dfs(vector<vector<int>>& image, int initialColor, int sr, int sc, int color) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != initialColor) {
            return;
        }

        image[sr][sc] = color;

        dfs(image, initialColor, sr+1, sc, color);
        dfs(image, initialColor, sr-1, sc, color);
        dfs(image, initialColor, sr, sc+1, color);
        dfs(image, initialColor, sr, sc-1, color);
    }
};
