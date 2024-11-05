class Solution {
public:
    bool isSubsequence(string s, string t) {
        int temp = 0;
        for(int i = 0; i < s.length(); i++){
            int check = false;
            if(temp == t.length()) {
                return false;
            }
            for(int j = temp; j < t.length(); j++) {
                if(s[i] == t[j]) {
                    temp = j;
                    temp++;
                    check = true;
                    break;
                }
            }
            if(!check) return false;
        }
        return true;
    }
};