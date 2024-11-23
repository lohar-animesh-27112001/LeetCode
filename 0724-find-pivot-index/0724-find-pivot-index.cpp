class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        for (int num : nums) right += num;
        for (int i = 0; i < n; i++) {
            right -= nums[i];
            if (left == right) return i;
            left += nums[i];
        }
        return -1;
    }
};
