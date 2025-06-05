class Solution {
private:
    int parent[26];

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        // Union by lexicographical order (smallest becomes parent)
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Initialize parent of each character to itself
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        // Union all equivalent characters
        for (int i = 0; i < s1.length(); i++)
            unionSet(s1[i] - 'a', s2[i] - 'a');

        // Build result
        string res = "";
        for (char c : baseStr)
            res += (char)(find(c - 'a') + 'a');
        
        return res;
    }
};
