#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                            {'C', 100}, {'D', 500}, {'M', 1000}};

        for(int i=1; i<s.size(); i++) {
            if(m.find(s[i-1])->second < m.find(s[i])->second) {
                number = number + m.find(s[i])->second - m.find(s[i-1])->second - m.find(s[i])->second;
            } else {
                number = number + (m.find(s[i-1])->second);
            }
        }
        number = number + m.find(s[s.size()-1])->second;
        return number;
    }
};