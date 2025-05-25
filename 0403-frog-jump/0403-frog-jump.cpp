using namespace std;

class Solution {
private:
    set<pair<int, int>> visited;

    void canCross(vector<int>& v, int k, bool &ans, int i) {
        if(ans) return;
        if(visited.count({i, k}) > 0) return;
        visited.insert({i, k});

        if(k-1 > 0) {
            auto it = find(v.begin(), v.end(), v[i] + k - 1);
            if(it != v.end()) {
                int idx = distance(v.begin(), it);
                if(idx == v.size() - 1) {
                    ans = true;
                    return;
                }
                canCross(v, k - 1, ans, idx);
            }
        }

        if(k > 0) {
            auto it = find(v.begin(), v.end(), v[i] + k);
            if(it != v.end()) {
                int idx = distance(v.begin(), it);
                if(idx == v.size() - 1) {
                    ans = true;
                    return;
                }
                canCross(v, k, ans, idx);
            }
        }

        auto it2 = find(v.begin(), v.end(), v[i] + k + 1);
        if(it2 != v.end()) {
            int idx = distance(v.begin(), it2);
            if(idx == v.size() - 1) {
                ans = true;
                return;
            }
            canCross(v, k + 1, ans, idx);
        }
    }

public:
    bool canCross(vector<int>& stones) {
        int k = 0, index = 0;
        bool ans = false;
        canCross(stones, k, ans, index);
        return ans;
    }
};
