class Solution {
private:
    int m = 0, n = 0;
    vector<vector<int>> dp;
    int edit_distance(string& s1, string& s2) {
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;
        for(int i = 0; i <= n; i++)
            dp[0][i] = i;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = min(dp[i-1][j-1], 
                            1 + min(dp[i-1][j], dp[i][j-1]));
                else
                    dp[i][j] = 1 + min(dp[i-1][j-1], 
                            min(dp[i-1][j], dp[i][j-1]));
        return dp[m][n];
    }
public:
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        dp.resize(m+1, vector<int>(n+1, 0));
        return edit_distance(word1, word2);
    }
};