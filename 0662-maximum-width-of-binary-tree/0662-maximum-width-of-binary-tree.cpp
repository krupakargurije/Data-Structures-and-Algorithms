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

using ll = unsigned long long;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root){
        if(!root)return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        ll maxWid = 0;

        while(!q.empty()){
            int currLevelLen = q.size();
            ll minIdx = q.front().second;
            ll start = 0 , end = 0;

            for(int i = 0;i<currLevelLen;i++){
                auto [node , idx] = q.front();
                q.pop();

                ll nIdx = idx - minIdx;
                
                if(i == 0)start = nIdx;
                if(i == currLevelLen - 1)end = nIdx;

                if(node->left)q.push({node->left , 2 * nIdx + 1});
                if(node->right)q.push({node->right , 2 * nIdx + 2});
            }
            maxWid = max(maxWid , end - start + 1);
        }
        return (int)maxWid;
    }
};