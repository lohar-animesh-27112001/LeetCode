class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        
        int r = v.size() - 1;
        int i = 0;
        
        while (i < r) {
            if (v[i] + v[r] > target) {
                r--;
            } else if (v[i] + v[r] < target) {
                i++;
            } else {
                int first = -1, second = -1;
                for (int k = 0; k < nums.size(); k++) {
                    if (nums[k] == v[i]) {
                        first = k;
                        break;
                    }
                }
                for (int k = 0; k < nums.size(); k++) {
                    if (nums[k] == v[r] && k != first) {
                        second = k;
                        break;
                    }
                }
                return {first, second};
            }
        }
        return {};
    }
    vector<int> twoSum2(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if((nums[i] + nums[j]) == target) {
                    vector<int> v = {i,j};
                    return v;
                }
            }
        }
        vector<int> v;
        return v;
    }
};