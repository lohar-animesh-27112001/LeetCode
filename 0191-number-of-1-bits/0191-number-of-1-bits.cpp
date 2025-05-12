class Solution {
public:
    int hammingWeight(int n) {
        int d = n;
        int ans = 0;
        while(d != 0 && d != 1) {
            if(d % 2 == 1) ans++;
            d = d / 2;
        }
        if(d == 1) return ++ans;
        return ans;
    }
};