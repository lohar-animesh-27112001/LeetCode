class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int node = 0; node < n; node++) {
            if(color[node] == -1) {
                if(dfs(node, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
    
private:
    bool dfs(int node, int col, vector<int> &color, vector<vector<int>>& graph) {
        color[node] = col;
        for(int i : graph[node]) {
            if(color[i] == -1) {
                if(!dfs(i, 1 - col, color, graph)) return false;
            } else if(color[i] == col) {
                return false;
            }
        }
        return true;
    }
};
