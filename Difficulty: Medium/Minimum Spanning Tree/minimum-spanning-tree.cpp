class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj[n];
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        priority_queue<
           pair<int,int>,
           vector<pair<int,int>>,
           greater<pair<int,int>>
        > pq;
        
        vector<int> vis(n,0);
        
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node] == 1)continue;
            vis[node] = 1;
            sum += wt;
            
            for(auto it : adj[node]){
                int nNode = it[0];
                int adjWt = it[1];
                
                if(!vis[nNode]){
                    pq.push({adjWt,nNode});
                }
                
            }
        }
        return sum;
    }
};



