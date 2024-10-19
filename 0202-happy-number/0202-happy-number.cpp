class Solution {
private:
    bool isHappy(int n, vector<int> &v) {
        if(n == 1) {
            return true;
        } else if(n  < 4) {
            return false;
        } else {
            for(int element : v) {
                if(element == n) {
                    return false;
                }
            }
            v.push_back(n);
            string str = to_string(n);
            int num = 0;
            for(char c : str) {
                num += pow(c - 48, 2);
            }
            return isHappy(num, v);
        }
    }
public:
    bool isHappy(int n) {
        vector<int> v;
        return isHappy(n, v);
    }
};