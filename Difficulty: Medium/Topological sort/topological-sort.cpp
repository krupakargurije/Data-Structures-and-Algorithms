class Solution {
  private:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,stack<int>& st){
        vis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        stack<int> st;
        
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
        }
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};