class Solution {
    vector<vector<int>> ans;
    void helper(vector<vector<int>> &adj){
        int n = adj.size();
        int m = adj[0].size();

        queue<pair<int , vector<int>>>q;

        q.push({0 , {0}});

        while(!q.empty()){
            auto [node , path] = q.front();
            q.pop();

            if(node == adj.size() - 1){
                ans.push_back(path);
                continue;
            }

            for(int it : adj[node]){
                vector<int> newPath = path;
                newPath.push_back(it);
                q.push({it, newPath});
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        helper(adj);
        return ans;
    }
};