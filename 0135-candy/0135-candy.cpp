class Solution {
private:
    int n = 0;

    void candy(vector<int>& v, int i, vector<int>& curr) {
        if(i == 0) curr[i] = 1;

        if(i >= n) return;

        // Forward step
        if(i > 0 && v[i] > v[i-1])
            curr[i] = curr[i-1] + 1;
        else
            curr[i] = 1;

        candy(v, i + 1, curr);
    }

    void reversePass(vector<int>& v, vector<int>& curr) {
        for(int i = n - 2; i >= 0; --i) {
            if(v[i] > v[i+1]) {
                curr[i] = max(curr[i], curr[i+1] + 1);
            }
        }
    }

public:
    int candy(vector<int>& ratings) {
        n = ratings.size();  // fix the shadowed n
        vector<int> arr(n, 0);

        // First pass: left to right
        candy(ratings, 0, arr);

        // Second pass: right to left
        reversePass(ratings, arr);

        int sum = 0;
        for(int i : arr) {
            sum += i;
        }
        return sum;
    }
};
