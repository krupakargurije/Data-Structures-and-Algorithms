class Solution {
    vector<vector<int>> ans;
    void helper(vector<vector<int>> &adj , vector<int> &curr , int node){
        int n = adj.size();

        if(node == n-1){
            ans.push_back(curr);
            return;
        }

        for(int it : adj[node]){
            curr.push_back(it);
            helper(adj , curr , it);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<int> curr;
        curr.push_back(0);
        helper(adj , curr , 0);
        return ans;
    }
};