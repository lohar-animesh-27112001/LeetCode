class Solution {
public:
    void sortColors(vector<int>& nums) {
        count_sort(nums);
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
};
