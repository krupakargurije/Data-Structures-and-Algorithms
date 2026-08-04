/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
    TreeNode* ans = NULL;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
            return false;
        
        bool left = helper(root->left , p , q);
        bool right = helper(root->right , p , q);
        bool self = (root == p || root == q);

        if(left && right || self && left || right && self)ans = root;
        return left || right || self;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root , p , q);
        return ans;
    }
};