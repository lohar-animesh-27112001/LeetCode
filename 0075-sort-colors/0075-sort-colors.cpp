class Solution {
public:
    void sortColors(vector<int>& nums) {
        count_sort_all(nums);
    }
private:
    void count_sort(vector<int> &nums) {
        int max = 2;
        vector<int> countArray(max + 1, 0);
        
        for(int i : nums) {
            countArray[i]++;
        }

        int index = 0;
        for(int i = 0; i <= max; i++) {
            while(countArray[i] > 0) {
                nums[index++] = i;
                countArray[i]--;
            }
        }
    }
    void count_sort_all(vector<int> &nums) {
        int max = 0;
        for(int i : nums) {
            if(i > max) {
                max = i;
            }
        }
        vector<int> countArray(max + 1, 0);
        for(int i : nums) {
            countArray[i] ++;
        }
        for(int i = 1; i <= max; i++) {
            countArray[i] += countArray[i - 1];
        }
        vector<int> outputArray(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            outputArray[countArray[nums[i]] - 1] = nums[i];
            countArray[nums[i]] --;
        }
        nums = outputArray;
    }
};
