class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int max = (1 << maximumBit) - 1;
        vector<int> ans;
        int xors = 0;
        for(int num : nums) {
            xors ^= num;
            ans.push_back(xors ^ max);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};