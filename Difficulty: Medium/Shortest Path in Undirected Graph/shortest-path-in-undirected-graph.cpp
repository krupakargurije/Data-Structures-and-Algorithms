class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dis(n,INT_MAX);
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i : adj[node]){
                if(dis[node] + 1 < dis[i]){
                    dis[i] = dis[node] +1;
                    q.push(i);
                }
            }
        }
        vector<int> ans(n,-1);
        
        for(int i = 0;i<n;i++){
            if(dis[i] != INT_MAX)ans[i] = dis[i];
        }
        return ans;
    }
};