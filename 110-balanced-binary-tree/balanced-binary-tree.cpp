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
    bool balanced = true;
    int helper(TreeNode* root){
        if(!root)return 0;

        int left = 1 + helper(root->left);
        int right = 1 + helper(root->right);

        if(abs(left - right) > 1){
            balanced = 0;
            return 0;
        }
        return max(left , right);
    }
public:
    bool isBalanced(TreeNode* root) {
        helper(root);
        return balanced;
    }
};