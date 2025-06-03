class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> hasBox(n, false), isOpen(n, false), visited(n, false);
        queue<int> q;

        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) {
                q.push(box);
                isOpen[box] = true;
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front(); q.pop();
            if (visited[box]) continue;
            visited[box] = true;

            totalCandies += candies[box];

            for (int key : keys[box]) {
                if (!isOpen[key] && hasBox[key]) {
                    q.push(key);
                }
                status[key] = 1;
                isOpen[key] = true;
                if (hasBox[key] && !visited[key])
                    q.push(key);
            }

            for (int newBox : containedBoxes[box]) {
                hasBox[newBox] = true;
                if (status[newBox] == 1 && !visited[newBox]) {
                    q.push(newBox);
                    isOpen[newBox] = true;
                }
            }
        }

        return totalCandies;
    }
};
