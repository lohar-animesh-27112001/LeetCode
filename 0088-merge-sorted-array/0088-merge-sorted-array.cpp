class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0 , j = 0, index = 0, total = m + n;
        while(m > i && n > j) {
            if(nums1[i + j] < nums2[j]) {
                index++;
                i++;
            } else {
                nums1.insert(nums1.begin() + index, nums2[j]);
                index++;
                j++;
            }
        }
        if(n > j) {
            while(n > j) {
                nums1[index] = nums2[j];
                index++;
                j++;
            }
        }
        nums1.resize(total);
    }
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0 , j = 0;
        vector<int> answer;
        while(m > i && n > j) {
            if(nums1[i] < nums2[j]) {
                answer.push_back(nums1[i]);
                i++;
            } else {
                answer.push_back(nums2[j]);
                j++;
            }
        }
        if(m > i) {
            while(m > i) {
                answer.push_back(nums1[i]);
                i++;
            }
        } else {
            while(n > j) {
                answer.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = answer;
    }
};