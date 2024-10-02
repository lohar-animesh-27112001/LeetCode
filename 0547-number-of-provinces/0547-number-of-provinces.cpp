class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsOfGraph(visited, i, isConnected);
                provinces++;
            }
        }
        return provinces;
    }

    void dfsOfGraph(vector<int> &visited, int node, vector<vector<int>> &isConnected) {
        stack<int> s;
        s.push(node);
        visited[node] = 1;

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            // Traverse neighbors in the adjacency matrix
            for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
                if (isConnected[curr][neighbour] == 1 && !visited[neighbour]) {
                    visited[neighbour] = 1;
                    s.push(neighbour);
                }
            }
        }
    }
};
