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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool getBool = false;
        hasPathSum(root, targetSum, sum, getBool);
        return getBool;
    }
private:
    void hasPathSum(TreeNode* node, int targetSum, int sum, bool &getBool) {
        if(node != NULL) {
            sum += node->val;
            hasPathSum(node->left, targetSum, sum, getBool);
            hasPathSum(node->right, targetSum, sum, getBool);
            if(node->left == NULL && node->right == NULL)
                if(sum == targetSum) getBool = true;
        }
    }
};