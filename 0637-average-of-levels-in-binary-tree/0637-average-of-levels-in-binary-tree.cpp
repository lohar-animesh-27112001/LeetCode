/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<TreeNode*>> v;
        vector<double> ans;
        if(root != NULL) {
            vector<TreeNode*> v_root;
            v_root.push_back(root);
            v.push_back(v_root);
        } else {
            return ans;
        }
        bool loop = true;
        while(loop) {
            vector<TreeNode*> v_back;
            v_back = v[v.size() - 1];
            vector<TreeNode*> v_child;
            for(TreeNode* node : v_back) {
                if(node->left != NULL) v_child.push_back(node->left);
                if(node->right != NULL) v_child.push_back(node->right);
            }
            if(v_child.size() == 0) loop = false;
            else v.push_back(v_child);
        }
        for(vector<TreeNode*> v_vec : v) {
            long long temp = 0;
            for(TreeNode* node : v_vec) temp += node->val;
            ans.push_back(static_cast<double>(temp) / v_vec.size());
        }
        return ans;
    }
};