/* Structure of Binary Tree Node
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
    int ans = 0;

    int dfs(Node* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int curr = 1;

        if (root->left && root->left->data == root->data + 1)
            curr = max(curr, 1 + left);

        if (root->right && root->right->data == root->data + 1)
            curr = max(curr, 1 + right);

        ans = max(ans, curr);
        return curr;
    }

public:
    int longestConsecutive(Node* root) {
        if (!root) return -1;

        dfs(root);
        return ans == 1 ? -1 : ans;
    }
};