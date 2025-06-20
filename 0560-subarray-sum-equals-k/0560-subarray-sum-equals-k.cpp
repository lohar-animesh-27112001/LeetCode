class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // This Approach will wprk only for positive integers

        // int i = 0, j = 0, n = nums.size(), ans = 0, sum = 0;
        // while(i < n || j < n) {
        //     cout << sum << " ";
        //     if(i == j && nums[i] == k) {
        //         ans++;
        //         j++;
        //         sum += nums[j];
        //     } else {
        //         if(sum == k) {
        //             ans++;
        //             if(j < n) {
        //                 sum += nums[j];
        //                 j++;
        //             } else {
        //                 sum -= nums[i];
        //                 i++;
        //             }
        //         } else {
        //             if(sum > k) {
        //                 sum -= nums[i];
        //                 i++;
        //             } else {
        //                 if(j < n) {
        //                     sum += nums[j];
        //                     j++;
        //                 } else {
        //                     sum -= nums[i];
        //                     i++;
        //                 }
        //             }
        //         }
        //     }
        // }

        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(int j = i; j < n; j++) {
                curr += nums[j];
                if(curr == k) ans++;
            }
        }
        return ans;
    }
};