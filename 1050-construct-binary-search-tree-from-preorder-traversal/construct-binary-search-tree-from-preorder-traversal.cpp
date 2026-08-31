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
    TreeNode* helper(vector<int> &preorder , int &idx , int upper){
        if(idx == preorder.size() || preorder[idx] > upper)
            return NULL;

        TreeNode *root = new TreeNode(preorder[idx++]);

        root->left = helper(preorder , idx , root->val);
        root->right = helper(preorder , idx , upper);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return helper(preorder , idx , INT_MAX);
    }
};