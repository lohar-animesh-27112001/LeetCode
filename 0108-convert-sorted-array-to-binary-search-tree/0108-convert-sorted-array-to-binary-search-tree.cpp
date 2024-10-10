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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        // Call the helper function to build the tree
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    // Helper function to build the BST
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        // Base case: if the left index exceeds the right, return nullptr
        if (left > right) {
            return nullptr;
        }

        // Find the middle element of the current subarray
        int mid = left + (right - left) / 2;

        // Create a new node with the middle element
        TreeNode* node = new TreeNode(nums[mid]);

        // Recursively build the left subtree with elements before the middle
        node->left = buildBST(nums, left, mid - 1);

        // Recursively build the right subtree with elements after the middle
        node->right = buildBST(nums, mid + 1, right);

        return node;
    }
};