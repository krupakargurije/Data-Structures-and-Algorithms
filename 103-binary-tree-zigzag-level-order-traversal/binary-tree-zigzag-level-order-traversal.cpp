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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};

        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>curr;

            while(n--){
                auto node = q.front();
                q.pop();

                curr.push_back(node->val);

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(curr);
        }

        for(int i = 1;i<ans.size();i += 2){
            reverse(ans[i].begin() , ans[i].end());
        }
        return ans;
    }
};