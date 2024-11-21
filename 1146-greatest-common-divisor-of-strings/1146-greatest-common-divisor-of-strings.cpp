class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length())
            return gcdOfStrings(str2, str1);

        if (str1.find(str2) != 0)
            return "";

        if (str2.empty())
            return str1;

        string remainder = mod(str1, str2);
        return gcdOfStrings(str2, remainder);
    }

private:
    string mod(const string &s1, const string &s2) {
        string temp = s1;
        while (temp.find(s2) == 0) {
            temp = temp.substr(s2.length());
        }
        return temp;
    }
};
