class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int sum = ans;
        for(int i : gain) {
            sum += i;
            ans = max(ans, sum);
        }
        return ans;
    }
};