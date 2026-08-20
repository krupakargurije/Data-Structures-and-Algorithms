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
    unordered_map<int , vector<int>>adj;
    int targetVal = -1;
    void dfs(TreeNode *root ){
        if(!root)return;

        int val = root->val;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }

        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        dfs(root->left);
        dfs(root->right);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);

        //node , dis->sorc
        queue<pair<int , int>>q;
        unordered_set<int>vis;

        q.push({target->val , 0});
        vis.insert(target->val);

        vector<int>ans;
        while(!q.empty()){
            auto [node , dis] = q.front();
            q.pop();

            if(dis == k){
                ans.push_back(node);
                continue;
            }

            for(auto it : adj[node]){
                if(vis.find(it) == vis.end()){
                    q.push({it , dis + 1});
                    vis.insert(it);
                }
            }
        }
        return ans;
    }
};