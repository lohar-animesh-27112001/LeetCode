class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int i : nums) {
            if(mp[i] > 0) {
                return true;
            } else {
                mp[i] = 1;
            }
        }
        return false;
    }
};