// User function Template for C++
class Solution {
  private:
    void dfs(int node,vector<int>& vis,stack<int>& st,
    vector<vector<pair<int,int>>>& adj){
        vis[node] = 1;
        for(auto i : adj[node]){
            int v = i.first;
            if(!vis[v]){
                dfs(v,vis,st,adj);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> vis(n,0);
        stack<int> st;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        vector<int> dis(n,INT_MAX);
        dis[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if (dis[node] != INT_MAX) {
                for (auto i : adj[node]) {
                    int v = i.first;
                    int wt = i.second;
                    
                    if (dis[node] + wt < dis[v]) {
                        dis[v] = dis[node] + wt;
                    }
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            if(dis[i] == INT_MAX)dis[i] = -1;
        }
        return dis;
    }
};
















