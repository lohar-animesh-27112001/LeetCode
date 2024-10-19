class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> temp_nums = nums;
        sort(temp_nums.begin(), temp_nums.end());
        return temp_nums[temp_nums.size() / 2];
    }
};