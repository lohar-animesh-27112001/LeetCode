class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if(n > 0) {
            answer.push_back(intervals[0]);
        }
        int ind = 0;
        for(int i = 1; i < n; i++) {
            vector<int> v = intervals[i];
            vector<int> v_back = answer[ind];
            if(v[0] <= v_back[1]) {
                answer[ind][1] = max(v[1], v_back[1]);
            } else {
                answer.push_back(v);
                ind++;
            }
        }
        return answer;
    }
};