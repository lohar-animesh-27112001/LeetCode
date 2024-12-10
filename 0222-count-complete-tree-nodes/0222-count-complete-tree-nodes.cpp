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
    int countNodes(TreeNode* root) {
        int count = 0;
        countNodes(root, count);
        return count;
    }
private:
    void countNodes(TreeNode* node, int &count) {
        if(node != NULL) {
            count++;
            countNodes(node->left, count);
            countNodes(node->right, count);
        }
    }
};