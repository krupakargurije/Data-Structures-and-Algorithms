class Solution {
private:
    int dfs(int node,vector<int>& vis,vector<int>& path,vector<int>& dep,vector<vector<int>>& adj){
        int ans = -1;
        vis[node] = 1;
        path[node] = 1;

        for(auto i:adj[node]){
            if(!vis[i]){
                dep[i] = dep[node]+1;
                int temp = dfs(i,vis,path,dep,adj);
                ans = max(ans,temp);
            }
            else if(path[i]){
                ans = max(ans,dep[node] - dep[i]+1);
            }
        }
        path[node] = 0;
        return ans;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);

        for(int i = 0;i<n;i++){
            if(edges[i] != -1)adj[i].push_back(edges[i]);
        }

        vector<int> vis(n,0),path(n,0),dep(n,0);
        int ans = -1;

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int temp = dfs(i,vis,path,dep,adj);
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};