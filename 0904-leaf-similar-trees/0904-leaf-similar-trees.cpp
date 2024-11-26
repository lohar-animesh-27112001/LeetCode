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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        traverse(root1, v1);
        traverse(root2, v2);
        if(v1 == v2) return true;
        else return false;
    }
private:
    void traverse(TreeNode* node, vector<int> &v) {
        if(node == NULL) return;
        traverse(node->left, v);
        traverse(node->right, v);
        if(node->left == NULL && node->right == NULL) v.push_back(node->val);
    }
};