class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int kMaxBit = 24;
        int ans = 0;
        for(int i = 0; i < kMaxBit; i++) {
            int count = 0;
            for(int candidate : candidates) {
                if(candidate >> i & 1) {
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};