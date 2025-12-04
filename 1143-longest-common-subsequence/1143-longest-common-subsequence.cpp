class Solution {
private:
    vector<vector<int>> mem;
    int m = 0, n = 0;
    int lcs(string &text1, string &text2) {
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    mem[i][j] = 1 + mem[i-1][j-1];
                } else {
                    mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
                }
            }
        }
        return mem[m][n];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.length();
        n = text2.length();
        mem.resize(m+1, vector<int>(n+1, 0));
        return lcs(text1, text2);
    }
};