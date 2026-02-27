/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        unordered_map<int , vector<int>>mp;
        queue<pair< Node* , int>>q;
        q.push({root , 0});
        
        int mn = INT_MAX,mx = INT_MIN;
        
        while(!q.empty()){
            auto [node , level] = q.front();
            q.pop();
            
            mn = min(mn , level);
            mx = max(mx , level);
            
            mp[level].push_back(node->data);
            
            if(node->left)q.push({node->left , level - 1});
            if(node->right)q.push({node->right , level + 1});
        }
        
        vector<int> ans;
        for(int i = mn;i<=mx;i++){
            auto it = mp[i];
            ans.push_back(it[0]);
        }
        
        return ans;
    }
};