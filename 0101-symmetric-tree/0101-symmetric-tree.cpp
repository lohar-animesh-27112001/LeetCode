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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        if(leftNode == nullptr && rightNode != nullptr) {
            return false;
        }
        if(leftNode != nullptr && rightNode == nullptr) {
            return false;
        }
        if(leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        if(leftNode->val != rightNode->val) {
            return false;
        }
        return isMirror(leftNode->left, rightNode->right) && 
        isMirror(leftNode->right, rightNode->left);
    }

    bool isSymmetric2(TreeNode* root) {
        vector <int> v1;
        vector <int> v2;
        inorder(root->left, v1);
        inorder(root->right, v2);
        reverse(v2.begin(), v2.end());
        if(v1 == v2) {
            return true;
        }
        return false;
    }

    void inorder(TreeNode* node, vector<int> &v) {
        if(node != nullptr) {
            inorder(node->left, v);
            v.push_back(node->val);
            inorder(node->right, v);
        }
    }
};