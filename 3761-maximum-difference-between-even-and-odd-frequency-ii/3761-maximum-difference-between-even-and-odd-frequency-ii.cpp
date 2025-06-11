class Solution {
 public:
  int maxDifference(string s, int k) {
    int ans = INT_MIN;
    // Iterate all ordered pairs (a, b) with a ≠ b
    for (char a = '0'; a <= '4'; ++a) {
      for (char b = '0'; b <= '4'; ++b) {
        if (a == b) continue;
        vector<vector<int>> minDiff(2, vector<int>(2, INT_MAX / 2));
        vector<int> preA(1, 0), preB(1, 0);
        int left = 0;
        // Expand window with right pointer
        for (int r = 0; r < s.size(); ++r) {
          preA.push_back(preA.back() + (s[r] == a));
          preB.push_back(preB.back() + (s[r] == b));
          while (r - left + 1 >= k &&
                 preA[left] < preA.back() &&
                 preB[left] < preB.back()) {
            minDiff[preA[left] % 2][preB[left] % 2] =
                min(minDiff[preA[left] % 2][preB[left] % 2],
                    preA[left] - preB[left]);
            ++left;
          }
          int pA = preA.back() % 2, pB = preB.back() % 2;
          ans = max(ans, (preA.back() - preB.back())
                             - minDiff[1 - pA][pB]);
        }
      }
    }
    return ans;
  }
};
