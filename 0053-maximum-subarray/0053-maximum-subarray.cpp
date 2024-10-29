class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long max = LONG_MIN;
        long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            cout << sum << " " << max << endl;
            if(sum > max) {
                max = sum;
            }
            if(sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};