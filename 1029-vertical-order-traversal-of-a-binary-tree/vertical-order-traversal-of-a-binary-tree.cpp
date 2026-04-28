class Solution {
private:
    void helper(TreeNode* root,
                map<int, vector<pair<int,int>>> &mp,
                int col, int row) {

        if (!root) return;

        mp[col].push_back({row, root->val});

        helper(root->left, mp, col - 1, row + 1);
        helper(root->right, mp, col + 1, row + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        helper(root, mp, 0, 0);
        vector<vector<int>> ans;

        for (auto &it : mp) {
            auto &vec = it.second;
            sort(vec.begin(), vec.end());

            vector<int> colVals;
            for (auto &p : vec) {
                colVals.push_back(p.second);
            }
            ans.push_back(colVals);
        }
        return ans;
    }
};