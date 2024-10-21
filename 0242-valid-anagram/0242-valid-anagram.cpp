class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> count(26, 0);
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (char c : t) {
            if (--count[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }

    bool isAnagram2(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        map<char, int> m1;
        map<char, int> m2;
        for(char c : s) {
            if(m1[c] == 0) {
                m1[c] = 1;
            } else {
                m1[c] += 1;
            }
        }
        for(char c : t) {
            if(m2[c] == 0) {
                m2[c] = 1;
            } else {
                m2[c] += 1;
            }
        }
        for(char c : t) {
            if(m1[c] != m2[c]) {
                return false;
            }
        }
        return true;
    }
};