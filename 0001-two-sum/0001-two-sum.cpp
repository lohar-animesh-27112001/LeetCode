class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int a = 0;
        for(int num : nums)
            um.insert({target - num, a++});
        a = 0;
        for(int num : nums) {
            auto i = um.find(num);
            if(i != um.end() && i->second != a)
                return {a, i->second};
            a++;
        }
        return {};
    }
};