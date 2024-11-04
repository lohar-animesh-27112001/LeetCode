class FenwickTree {
public:
    FenwickTree(int n) : sums(n + 1) {}
    void update(int i, int delta) {
        while(i < sums.size()) {
            sums[i] += delta;
            i += lowbit(i);
        }
    }
    int get(int i) {
        int sum = 0;
        while(i > 0) {
            sum += sums[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    vector<int> sums;
    static int lowbit(int i) {
        return i & -i;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        unordered_map<int, int> ranks;
        getRanks(nums, ranks);
        FenwickTree tree(ranks.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i];
            ans[i] = tree.get(ranks[num] - 1);
            tree.update(ranks[num], 1);
        }
        return ans;
    }
    vector<int> count_smaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(nums[j] < nums[i]) {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
private:
    void getRanks(vector<int> &nums, unordered_map<int, int> &ranks) {
        set<int> sorted(nums.begin(), nums.end());
        int rank = 0;
        for(int num : sorted) {
            ranks[num] = ++rank;
        }
    }
};