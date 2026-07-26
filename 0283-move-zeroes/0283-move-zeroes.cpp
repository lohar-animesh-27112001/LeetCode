class Solution {
private:
    vector<int> sortingSegregateElements(vector<int>& arr, int n) {
        vector<int> count_min;
        vector<int> count_max;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) count_min.push_back(i);
            else count_max.push_back(i);
        }
        int min = count_min.size();
        int max = count_max.size();
        vector<int> ans;
        for(int i = 0; i < max; i++) {
            ans.push_back(arr[count_max[i]]);
        }
        for(int i = 0; i < min; i++) {
            ans.push_back(arr[count_min[i]]);
        }
        return ans;
    }
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        nums = sortingSegregateElements(nums, n);
    }
};