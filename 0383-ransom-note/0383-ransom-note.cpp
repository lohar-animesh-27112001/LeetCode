class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);
        for(char c : magazine) count[c - 97]++;
        for(char c : ransomNote) if(--count[c - 97] < 0) return false;
        return true;
    }
};