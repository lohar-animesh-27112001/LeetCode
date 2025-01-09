class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a = 0, b = 0, c = 0, d = nums.size();
        for(int i = 0; i < d; i++) {
            if(nums[i] == 1) {
                a++;
            } else {
                b = a;
                a = 0;
            }
            c = max(b + a, c);
        }
        if(c == d) return d - 1;
        return c;
    }
};