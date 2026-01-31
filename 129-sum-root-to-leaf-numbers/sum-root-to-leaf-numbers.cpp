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
void help(TreeNode* root,int &sum,int tar)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        tar=tar*10;
        tar+=root->val;
        sum+=tar;
        return;
    }
    tar=tar*10;
    tar+=root->val;
    help(root->left,sum,tar);
    help(root->right,sum,tar);

}
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int tar=0;
        help(root,sum,tar);
        return sum;
    }
};