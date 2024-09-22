class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome(0, to_string(x).length()-1, to_string(x));
    }
    bool isPalindrome(int i, int r, string str) {
        if(i>r) {
            return true;
        } else if(str[i] != str[r]) {
            return false;
        } else {
            return isPalindrome(i+1, r-1, str);
        }
    }
};