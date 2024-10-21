class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[first++] = nums[i];
            }
        }
        for(int i = first; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};