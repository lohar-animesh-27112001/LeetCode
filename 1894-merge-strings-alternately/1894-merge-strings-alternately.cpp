class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str = "";
        int i = 0;
        int j = 0;
        int n = word1.length();
        int m = word2.length();
        while(i < n || j < m) {
            if(i < n) {
                str = str + word1[i];
                i++;
            }
            if(j < m) {
                str = str + word2[j];
                j++;
            }
        }
        return str;
    }
};