class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> mp;
        for(int i : nums1) {
            mp[i] = mp[i] + 1;
        }
        for(int i : nums2) {
            auto it = mp.find(i);
            if(it != mp.cend() && it->second > 0) {
                ans.push_back(i);
                it->second--;
            }
        }
        return ans;
    }
};