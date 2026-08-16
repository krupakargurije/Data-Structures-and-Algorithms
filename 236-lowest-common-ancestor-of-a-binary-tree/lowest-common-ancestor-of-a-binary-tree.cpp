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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;
        if(root->val == q->val || root->val == p->val)return root;

        TreeNode* lv = lowestCommonAncestor(root->left,p,q);
        TreeNode* rv = lowestCommonAncestor(root->right,p,q);

        if(lv && rv)return root;
        return lv ? lv : rv;
    }
};