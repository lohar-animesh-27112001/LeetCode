class Solution {
public:
    string compressedString(string word) {
        string answer = "";
        int n = word.length();
        for(int i = 0, j = 0; i < n; i = j) {
            int count = 0;
            while(j < n & word[j] == word[i] && count < 9) {
                j++;
                count++;
            }
            answer += to_string(count) + word[i];
        }
        return answer;
    }
};