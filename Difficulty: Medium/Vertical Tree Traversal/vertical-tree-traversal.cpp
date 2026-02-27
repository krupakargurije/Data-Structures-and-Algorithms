/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        unordered_map<int , vector<int>>mp;
        queue<pair<Node* , int>>q;
        
        q.push({root , 0});
        
        int mx = INT_MIN , mn = INT_MAX;
        
        while(!q.empty()){
            auto [node , level] = q.front();
            q.pop();
            
            mx = max(mx , level);
            mn = min(mn , level);
            
            mp[level].push_back(node->data);
            
            if(node->left)q.push({node->left , level - 1});
            if(node->right)q.push({node->right , level + 1});
        }
        
        vector<vector<int>>ans;
        for(int i = mn;i <= mx;i++)ans.push_back(mp[i]);
        
        return ans;
    }
};


