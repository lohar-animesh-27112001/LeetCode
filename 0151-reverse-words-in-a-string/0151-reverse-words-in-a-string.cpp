class Solution {
public:
    string reverseWords(string s) {
        reverseString(s, s.length());
        reverseWordsInPlace(s, s.length());
        return cleanSpaces(s, s.length());
    }

private:
    void reverseString(string &s, int n) {
        for(int i = 0; i < n / 2; i++) {
            swapChar(s, i, n - i - 1);
        }
    }

    void swapChar(string &s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

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