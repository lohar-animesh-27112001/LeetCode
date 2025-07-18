class Solution {
private:
    int m = 0, n = 0;
    vector<vector<int>> dp;
    bool ans = false;
    bool isMatch(string& s, string& p, int i, int j) {
        if(i == m && j == n) {
            ans = true;
            return true;
        }
        if(i > m || j > n) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool match = false;
        if(p[j] == '*') {
            match = isMatch(s, p, i+1, j) || 
            isMatch(s, p, i, j+1) || 
            isMatch(s, p, i+1, j+1);
        }
        if(i < m && j < n && (s[i] == p[j] || p[j] == '?'))
            match = isMatch(s, p, i+1, j+1);
        return dp[i][j] = match;
    }
public:
    bool isMatch(string s, string p) {
        m = s.length(), n = p.length();
        dp.resize(m+1, vector<int>(n+1, -1));
        isMatch(s, p, 0, 0);
        return ans;
    }
};