class Solution {
private:
    int large(vector<int> arr) {
        int max = INT_MIN;
        for(int i : arr)
            if(i > max)
                max = i;
        return max;
    }
    int small(vector<int> arr) {
        int min = INT_MAX;
        for(int i : arr)
            if(i < min)
                min = i;
        return min;
    }
    int GCD(int i, int j) {
        if(i == 1 || j == 1) return 1;
        if(i == j) return i;
        if(i > j)
            if((i % (i-j)) == 0 && (j % (i-j)) == 0)
                return i-j;
            else
                return GCD(j, i-j);
        else
            if((i % (j-i)) == 0 && (j % (j-i)) == 0)
                return j-i;
            else
                return GCD(i, j-i);
    }
public:
    int findGCD(vector<int>& nums) {
        int max = large(nums);
        int min = small(nums);
        return GCD(max, min);
    }
};