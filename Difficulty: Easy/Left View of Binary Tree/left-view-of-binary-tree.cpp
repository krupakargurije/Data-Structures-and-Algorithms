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
    vector<int> leftView(Node *root) {
        if(!root)return {};
        vector<int> ans;
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            
            while(n--){
                auto it = q.front();
                q.pop();
                
                if(!flag){
                    ans.push_back(it->data);
                    flag = true;
                }
                
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
        }
        return ans;
    }
};