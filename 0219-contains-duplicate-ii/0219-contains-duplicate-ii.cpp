class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> begin;
        for(int i = 0; i < nums.size(); i++) {
            if(begin.find(nums[i]) == begin.end()) begin[nums[i]] = i;
            else if((i - begin[nums[i]]) <= k) return true;
            else begin[nums[i]] = i;
        }
        return false;
    }
};