class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size() - 1;
        int space = 0;
        while(s[len] == ' ') {
            space++;
            len--;
        }
        while(len >= 0) {
            if(s[len] == ' ') {
                return s.size() - len - 1 - space;
            }
            len--;
        }
        return s.size() - space;
    }
};