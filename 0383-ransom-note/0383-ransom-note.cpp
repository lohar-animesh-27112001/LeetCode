class Solution {
public:
    bool canConstruct2(string ransomNote, string magazine) {
        map<char, int> count;
        for(char c : magazine) count[c]++;
        for(char c : ransomNote) if(--count[c] < 0) return false;
        return true;
    }
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);
        for(char c : magazine) count[c - 97]++;
        for(char c : ransomNote) if(--count[c - 97] < 0) return false;
        return true;
    }
};