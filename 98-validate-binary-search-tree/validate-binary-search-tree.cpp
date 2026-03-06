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
    bool helper(TreeNode* root , long long max , long long min){
        if(!root)return true;

        if(root->val <= min || root->val >= max)return false;

        return helper(root->left , root->val , min) 
            && helper(root->right , max , root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root , LLONG_MAX, LLONG_MIN);
    }
};