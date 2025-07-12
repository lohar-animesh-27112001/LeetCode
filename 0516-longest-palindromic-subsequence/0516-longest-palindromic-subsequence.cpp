class Solution {
private:
    int m = 0;
    vector<vector<int>> dp;

    void reverse_str(string& str) {
        int n = str.length();
        for(int i = 0; i < n / 2; i++) {
            char c = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = c;
        }
    }

    void print_lcs(string& text1, string& text2) {
        int i = m, j = m;
        string str = "";
        while(i > 0 && j > 0) {  // ✅ Fixed bounds check
            if(text1[i - 1] == text2[j - 1]) {
                str += text1[i - 1];
                i--;
                j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse_str(str);
        cout << "So the LCS is: " << str << endl;
    }

    int lcs(string& text1, string& text2) {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        print_lcs(text1, text2);
        return dp[m][m];
    }

    int lps(string& text) {
        m = text.length();
        dp.resize(m + 1, vector<int>(m + 1, 0));
        string reversed_text = text;
        reverse_str(reversed_text);
        return lcs(text, reversed_text);
    }

public:
    int longestPalindromeSubseq(string s) {
        return lps(s);
    }
};
