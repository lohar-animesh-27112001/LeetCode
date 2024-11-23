class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        string ans;
        for(char c : s) {
            if(isVowel(c)) {
                vowels = vowels + c;
            }
        }
        if(vowels.length() == 0) {
            return s;
        }
        reverse(vowels.begin(), vowels.end());
        int i = 0;
        for(char c : s) {
            if(isVowel(c)) {
                ans += vowels[i++];
            } else {
                ans += c;
            }
        }
        return ans;
    }
private:
    bool isVowel(char c) {
        string vowels = "AEIOUaeiou";
        return vowels.find(c) != string::npos;
    }
};