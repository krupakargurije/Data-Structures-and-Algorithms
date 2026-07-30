class Solution {
    private:
    void helper(int i , vector<int> &vis , stack<int> &st , vector<vector<int>> &adj){
        vis[i] = 1;
        
        for(int it : adj[i]){
            if(!vis[it]){
                helper(it , vis , st , adj);
            }
                
        }
        st.push(i);
    }
  public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<int>vis(n , 0);
        stack<int>st;
        
        for(int i = 0;i<n;i++){
            if(!vis[i])
                helper(i , vis , st , adj);
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};