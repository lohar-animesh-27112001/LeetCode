class Solution {
private:
    vector<string> split(string sentence, char splited_char) {
        string str = "";
        vector<string> str_vec;
        int n = sentence.size();
        for(int i = 0; i < n; i++) {
            if(sentence[i] != splited_char) {
                str.push_back(sentence[i]);
            } else {
                str_vec.push_back(str);
                str = "";
            }
        }
        if(!str.empty()) {  // Add the last word if non-empty
            str_vec.push_back(str);
        }
        return str_vec;
    }
public:
    bool isCircularSentence(string sentence) {
        vector<string> splited_sentence = split(sentence, ' ');
        int n = splited_sentence.size();
        if(n == 0) return true;

        if(n == 1) {
            return splited_sentence[0].front() == splited_sentence[0].back();
        }

        for(int i = 1; i < n; i++) {
            if(splited_sentence[i - 1].back() != splited_sentence[i].front()) {
                return false;
            }
        }
        return splited_sentence[n - 1].back() == splited_sentence[0].front();
    }
};
