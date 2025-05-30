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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        getHeight(root, balanced);
        return balanced;
    }
    int getHeight(TreeNode* node, bool &balanced) {
        if(node == nullptr) {
            return 0;
        }
        int leftNode = getHeight(node->left, balanced);
        int rightNode = getHeight(node->right, balanced);
        if((leftNode - rightNode) > 1 || (leftNode - rightNode) < -1) {
            balanced = false;
        }
        return 1 + max(leftNode, rightNode);
    }
};