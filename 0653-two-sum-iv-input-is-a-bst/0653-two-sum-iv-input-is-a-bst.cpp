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
    bool helper(TreeNode *root , int k , unordered_set<int> &st){
        if(!root)
            return false;
        
        int req = k - root->val;
        if(st.find(req) != st.end())
            return true;
        
        st.insert(root->val);

        bool left = helper(root->left , k , st);
        bool right = helper(root->right , k , st);

        return left || right;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        return helper(root , k , st);
    }
};