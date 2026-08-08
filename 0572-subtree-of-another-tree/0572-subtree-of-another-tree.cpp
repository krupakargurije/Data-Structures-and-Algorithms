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
    void helper(TreeNode* root , string &str){
        if(!root){
            str.push_back('#');
            return;
        }

        str.push_back(root->val);
        str+= ',';
        helper(root->left , str);
        helper(root->right , str);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* sroot) {
        if(!root || !sroot)return root == sroot;
        string r = "" , s = "";
        helper(root , r);
        helper(sroot , s);

        return r.find(s) != string::npos;
    }
};