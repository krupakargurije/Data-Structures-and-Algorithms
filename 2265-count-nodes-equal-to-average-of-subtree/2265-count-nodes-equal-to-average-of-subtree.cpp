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
    pair<int , int> helper(TreeNode *root){
        if(!root)
            return {0 , 0};
        
        auto [leftSum , leftNodes] = helper(root->left);
        auto [rightSum , rightNodes] = helper(root->right);

        int n = leftNodes + rightNodes + 1;
        int sum = leftSum + rightSum + root->val;

        int average = sum / n;

        if(root->val == average)
            ans++;
        return {sum , n};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};