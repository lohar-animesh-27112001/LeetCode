class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;
        dfs(image, initialColor, sr, sc, color);
        return image;
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
