class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> count(n + 1, false);
        for (int i : nums) {
            count[i] = true;
        }
        for (int i = 0; i <= n; i++) {
            if (!count[i]) {
                return i;
            }
        }
        return n;
    }
};
