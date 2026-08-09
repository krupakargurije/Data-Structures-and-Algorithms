class Solution {
    private:
    bool helper(int src , vector<vector<int>> &adj , int n , vector<int> &vis){
        queue<pair<int , int>>q;
        
        q.push({src , -1});
        vis[src] = 1;
        
        while(!q.empty()){
            auto [node , parent] = q.front();
            q.pop();
            
            for(int &it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it , node});
                }
                else if(it != parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n , 0);
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(helper(i , adj , n , vis))
                    return true;
            }
        }
        return false;
    }
};