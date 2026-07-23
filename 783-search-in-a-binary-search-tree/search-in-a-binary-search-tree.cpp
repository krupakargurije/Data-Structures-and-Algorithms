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
    TreeNode* searchBST(TreeNode* root, int t) {
        if(!root)
            return NULL;
        if(root->val == t)
            return root;
        
        TreeNode *left = NULL , *right = NULL;
        if(t < root->val)
            left = searchBST(root->left , t);
        
        if(t > root->val)
            right = searchBST(root->right , t);
        
        return left ? left : right;
    }
};