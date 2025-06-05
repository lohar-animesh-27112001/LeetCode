class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;
        string s = lastSubstring(word);
        int sz = word.length() - numFriends + 1;
        return s.substr(0, min((int)s.length(), sz));
    }

private:
    // Function to find the lexicographically last substring
    string lastSubstring(const string& s) {
        int n = s.length();
        int i = 0, j = 1, k = 0;
        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                ++k;
            } else if (s[i + k] > s[j + k]) {
                j = j + k + 1;
                k = 0;
            } else {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
