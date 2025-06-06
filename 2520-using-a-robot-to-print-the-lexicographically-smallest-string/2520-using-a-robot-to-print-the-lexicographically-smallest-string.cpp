class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minChar(n);
        minChar[n-1] = s[n-1];
        
        // Build suffix minimum array
        for (int i = n-2; i >= 0; --i)
            minChar[i] = min(s[i], minChar[i+1]);
        
        stack<char> st;
        string result;
        
        for (int i = 0; i < n; ++i) {
            st.push(s[i]);
            
            // While top of stack ≤ min of remaining chars, pop
            while (!st.empty() && st.top() <= minChar[i+1 == n ? n-1 : i+1]) {
                result += st.top();
                st.pop();
            }
        }
        
        // Empty the stack
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};
