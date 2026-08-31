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
    private:
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;

    void helper(TreeNode* root) {
        if (!root)
            return;

        // Left
        helper(root->left);

        // Current
        if (prev && prev->val > root->val) {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;

        // Right
        helper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        helper(root);

        swap(first->val , second->val);
    }
};