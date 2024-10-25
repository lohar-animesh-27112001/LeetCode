class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        string prev;
        ranges::sort(folder);
        for(string &str : folder) {
            if(!prev.empty() && str.find(prev) == 0 && str[prev.length()] == '/') {
                continue;
            }
            ans.push_back(str);
            prev = str;
        }
        return ans;
    }
};