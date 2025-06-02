class Solution {
private:
    int n = 0;
    void candy(vector<int>& ratings, int i, int c, vector<int>& curr) {
        if (i >= n) return;
        curr[i] = max(curr[i], c);
        if (i + 1 < n) {
            if (ratings[i + 1] > ratings[i])
                candy(ratings, i + 1, curr[i] + 1, curr);
            else candy(ratings, i + 1, 1, curr);
            if (ratings[i] > ratings[i + 1] && curr[i] <= curr[i + 1])
                curr[i] = curr[i + 1] + 1;
        }
    }
public:
    int candy(vector<int>& ratings) {
        n = ratings.size();
        vector<int> arr(n, 1);
        candy(ratings, 0, 1, arr);
        int sum = 0;
        for (int i : arr)
            sum += i;
            // cout << i << " ";
        return sum;
    }
};
