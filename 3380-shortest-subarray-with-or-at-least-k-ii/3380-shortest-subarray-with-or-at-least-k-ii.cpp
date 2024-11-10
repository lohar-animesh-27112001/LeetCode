class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int kMax = 50;
        int n = nums.size();
        int ans = n + 1;
        int ors = 0;
        vector<int> count(kMax + 1);
        for(int i = 0, r = 0; r < n; r++) {
            ors = orNum(ors, nums[r], count);
            while(ors >= k && i <= r) {
                ans = min(ans, r - i + 1);
                ors = undoOrNum(ors, nums[i], count);
                ++i;
            }
        }
        return (ans == n + 1) ?  -1 : ans;
    }
private:
    int kMaxBit = 30;
    int orNum(int ors, int num, vector<int> &count) {
        for(int i = 0; i < kMaxBit; i++) {
            if(num >> i & 1 && ++count[i] == 1) {
                ors += 1 << i;
            }
        }
        return ors;
    }
    int undoOrNum(int ors, int num, vector<int>& count) {
        for(int i = 0; i < kMaxBit; i++) {
            if(num >> i & 1 && --count[i] == 0) ors -= 1 << i;
        }
        return ors;
    }
};