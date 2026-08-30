class Solution {
public:
    int ans = -1;
    int n;
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);     
        
        n--;
        if(!n){
            ans = root->val;
            return;
        }
        inOrder(root->right);    
    }

    int kthSmallest(TreeNode* root, int k) {
        n = k;
        inOrder(root);
        return ans;
    }
};
