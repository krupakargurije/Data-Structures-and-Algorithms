// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
        vector<int> dis(n,1e8);
        dis[src] = 0;
        
        for(int i = 0;i<n-1;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dis[u] != 1e8 && dis[u] + wt < dis[v]){
                    dis[v] = dis[u] + wt;
                }
            }
        }
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dis[u] != 1e8 && dis[u] + wt < dis[v]){
                return {-1};
            }
        }
        return dis;
    }
};
