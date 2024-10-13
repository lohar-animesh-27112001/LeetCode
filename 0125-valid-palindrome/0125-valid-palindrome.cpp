class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, r = s.length() - 1;
        while(i < r) {
            while(i < r && !isalnum(s[i])) {
                ++i;
            }
            while(i < r && !isalnum(s[r])) {
                --r;
            }
            if(tolower(s[i]) != tolower(s[r])) {
                return false;
            }
            ++i;
            --r;
        }
        return true;
    }
        bool isPalindrome2(string s) {
        if(s.size() == 0) {
            return true;
        }
        string s2;
        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                s2 = s2 + s[i];
            }
        }
        cout << s2;
        std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        for(int i = 0; i < s2.size() / 2; i++) {
            if(s2[i] != s2[s2.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};