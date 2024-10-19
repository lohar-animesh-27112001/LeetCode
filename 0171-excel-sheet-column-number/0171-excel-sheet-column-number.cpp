class Solution {
public:
    int titleToNumber(string columnTitle) {
        long ans = 0;
        int n = columnTitle.length();
        for(int i = 0; i < n; i++) {
            ans += ((columnTitle[n - i - 1] - 65 + 1) * pow(26, i)); // 'A' = 65;
        }
        return ans;
    }
};