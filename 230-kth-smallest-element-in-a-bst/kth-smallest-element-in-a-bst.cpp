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
    // vector<int> arr;
    int ans = -1;
    int n;
    void differ(TreeNode* root){
        if(root == NULL)return;
        differ(root->left);
        n--;
        if(n == 0){
            ans = root->val;
            return;
        }
        differ(root->right);
    }
    int kthSmallest(TreeNode* root, int k){
        n = k;
        differ(root);
        return ans;
    }
};