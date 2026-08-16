/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(!root)return false;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(!node->left && !node->right)continue;
            
            int left = node->left ? node->left->data : 0;
            int right = node->right ? node->right->data : 0;
            
            if(node->data != left + right)return false;
            
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return true;
    }
};