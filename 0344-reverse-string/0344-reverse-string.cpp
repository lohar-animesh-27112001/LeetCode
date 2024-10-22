class Solution {
private:
    void swapChar(vector<char> &s, int i, int j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i++) {
            swapChar(s, i, s.size() - i - 1);
        }
    }
};