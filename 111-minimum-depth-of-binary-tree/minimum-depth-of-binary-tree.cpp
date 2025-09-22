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

    int helper (TreeNode * root){
        if (root == NULL) return 0;
        int leftdep = helper(root->left);
        int rightdep = helper(root->right);
        if (root->left ==NULL){
            return  rightdep+1;

        }
        if (root-> right == NULL){
            return leftdep+1;

        }
        else{
            return min (leftdep,rightdep)+1;
        }
    }
    int minDepth(TreeNode* root) {
        return helper (root);
    }
};