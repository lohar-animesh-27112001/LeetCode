class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int num : nums) {
            auto pos = lower_bound(v.begin(), v.end(), num);
            if(pos == v.end()) {
                if(v.size() == 0 || (v.size() != 0 && v[v.size() - 1] != num)) {
                    v.push_back(num);
                }
            } else {
                *pos = num;
            }
        }
        return v.size();
    }
};