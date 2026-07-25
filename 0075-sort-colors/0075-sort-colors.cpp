class Solution {
private:
    void sort012(vector<int> &arr, int n) {
        int lo = 0, mid = 0, hi = n-1;
        while(mid <= hi) {
            if(arr[mid] == 0) {
                swap(arr[lo++], arr[mid++]);
            } else if(arr[mid] == 1) {
                mid++;
            } else {
                swap(arr[mid], arr[hi--]);
            }
        }
    }
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        sort012(nums, n);
    }
};