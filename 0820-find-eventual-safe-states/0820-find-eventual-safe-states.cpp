class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int v = graph.size();
        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);
        vector<int> safeNodes;

        for (int i = 0; i < v; i++)
            if (!vis[i])
                dfsCheck(graph, i, vis, pathVis, safeNodes);

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }

private:
    bool dfsCheck(const vector<vector<int>>& graph, int node, vector<int>& vis, vector<int>& pathVis,
                  vector<int>& safeNodes) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfsCheck(graph, it, vis, pathVis, safeNodes)) return true;
            } else if (pathVis[it]) return true;
        }

        safeNodes.push_back(node);
        pathVis[node] = 0;
        return false;
    }
};