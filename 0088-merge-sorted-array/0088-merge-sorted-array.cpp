class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        int i=0, j=0;
        while(i<m && j<n) {
            if(nums1[i] > nums2[j]) {
                v.push_back(nums2[j]);
                j++;
            } else {
                v.push_back(nums1[i]);
                i++;
            }
        }
        if(i<m) {
            for(i; i<m; i++) {
                v.push_back(nums1[i]);
            }
        }
        if(j<n) {
            for(j; j<n; j++) {
                v.push_back(nums2[j]);
            }
        }

        nums1 = v;
    }
};