class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        reverseWordsInPlace(s, s.length());
        return cleanSpaces(s, s.length());
    }

private: 
    void reverseWordsInPlace(string &s, int n) {
        int i = 0, j = 0;
        while (i < n) {
            while (i < j || (i < n && s[i] == ' ')) i++;
            while (j < i || (j < n && s[j] != ' ')) j++;
            reverse(s.begin() + i, s.begin() + j);
        }
    }

    string cleanSpaces(string &s, int n) {
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j++;
            while (j < n && s[j] != ' ') s[i++] = s[j++];
            while (j < n && s[j] == ' ') j++;
            if (j < n) s[i++] = ' ';
        }
        return s.substr(0, i);
    }
};