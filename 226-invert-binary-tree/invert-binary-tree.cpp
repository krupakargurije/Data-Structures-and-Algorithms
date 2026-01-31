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
    TreeNode* helper(TreeNode* root){
        if(!root)return NULL;
        if(!root->left && !root->right)return root;

        TreeNode* left = helper(root->left);
        TreeNode* right = helper(root->right);
        root->right = left;
        root->left = right;
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        return helper(root);
    }
};