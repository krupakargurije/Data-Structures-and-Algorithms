class Solution {
    private:
    vector<int> helper(int n , vector<vector<int>> &adj , vector<int> &vis){
        queue<int>q;
        q.push(n);
        vis[n] = 1;
        
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int &it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return ans;
    }
  public:
    vector<vector<int>> getComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>>ans;
        vector<int>vis(n , 0);
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                vector<int> curr = helper(i , adj , vis);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
