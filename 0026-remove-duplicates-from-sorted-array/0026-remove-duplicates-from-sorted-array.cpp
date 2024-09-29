class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        if(nums.size() == 1) {
            return 1;
        }
        for(int i=0; i<=nums.size()-2; i++) {
            if(nums[i] != nums[i+1]) {
                v.push_back(nums[i]);
            }
        }
        v.push_back(nums[nums.size()-1]);
        nums = v;
        return nums.size();
    }
};