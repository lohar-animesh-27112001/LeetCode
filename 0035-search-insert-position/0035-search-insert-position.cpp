class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(find(nums.begin(), nums.end(), target) != nums.end()) {
            return distance(nums.begin(), find(nums.begin(), nums.end(), target));
        } else {
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] > target) {
                    return i;
                }
            }
        }
        return nums.size();
    }
};