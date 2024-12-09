class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int pre = nums[i];
            while(i < n - 1 && nums[i] + 1 == nums[i + 1]) i++;
            int next = nums[i];
            if(pre == next) ans.push_back(to_string(pre));
            else ans.push_back(to_string(pre) + "->" + to_string(next));
        }
        return ans;
    }
};