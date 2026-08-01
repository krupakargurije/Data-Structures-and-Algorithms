class Solution {
    private:
    bool helper(int node , vector<vector<int>> &adj ,
    vector<int> &vis , vector<int> &path){
        
        vis[node] = 1;
        path[node] = 1;
        
        for(int i : adj[node]){
            if(!vis[i]){
                if(helper(i , adj , vis , path))
                    return true;
            }
            
            else if(path[i])
                return true;
        }
        path[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int n, vector<vector<int>> &edges) {
        vector<vector<int>>adj(n);
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<int>vis(n , 0);
        vector<int>path(n , 0);
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(helper(i , adj ,vis, path))
                    return true;
            }
        }
        return false;
    }
};