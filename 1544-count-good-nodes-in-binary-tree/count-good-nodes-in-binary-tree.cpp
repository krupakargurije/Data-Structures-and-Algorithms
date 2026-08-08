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
    int ans = 0;
    void helper(TreeNode* root , int mx){
        if(!root)return;

        helper(root->left , max(mx , root->val));
        helper(root->right , max(mx , root->val));
        if(root->val >= mx)ans++;
    }
public:
    int goodNodes(TreeNode* root) {
        helper(root , INT_MIN);
        return ans;
    }
};