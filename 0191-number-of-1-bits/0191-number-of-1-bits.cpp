class Solution {
public:
    int hammingWeight(int n) {
        vector<int> v;
        while(n > 1) {
            if(n % 2 == 1) {
                v.push_back(1);
            }
            n = n/2;
        }
        if(n == 1) {
            return v.size() + 1;
        }
        return v.size();
    }
};