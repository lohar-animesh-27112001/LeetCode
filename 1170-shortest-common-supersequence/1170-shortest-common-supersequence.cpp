class Solution {
private:
    int m = 0;
    int n = 0;
    vector<vector<int>> dp;

    void reverse_str(string& str) {
        int n = str.length();
        for(int i = 0; i < n / 2; i++) {
            char c = str[i];
            str[i] = str[n-i-1];
            str[n-i-1] = c;
        }
    }

    string print_lcs(string& text1, string& text2) {
        int i = m, j = n;
        string str = "";
        while(i > 0 && j > 0) {
            if(text1[i-1] == text2[j-1]) {
                str += text1[i-1];
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                str += text1[i-1];
                i--;
            } else {
                str += text2[j-1];
                j--;
            }
        }
        while(i > 0) {
            str += text1[i - 1];
            i--;
        }
        while(j > 0) {
            str += text2[j - 1];
            j--;
        }
        reverse_str(str);
        return str;
    }

    string lcs(string& text1, string& text2) {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        return print_lcs(text1, text2);
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        m = str1.length();
        n = str2.length();
        dp.resize(m+1, vector<int>(n+1, 0));
        return lcs(str1, str2);;
    }
};