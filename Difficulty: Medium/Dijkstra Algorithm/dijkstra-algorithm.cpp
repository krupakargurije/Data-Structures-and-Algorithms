// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj[n];
        
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
        }
        
        
        vector<int> dis(n,INT_MAX);
        set<pair<int,int>> st;
        st.insert({0,src});
        dis[src] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            
            int node = it.second;
            int distance = it.first;
            
            for(auto i : adj[node]){
                int newNode = i[0];
                int wt = i[1];
                
                if(wt + distance < dis[newNode]){
                    if(dis[newNode] != INT_MAX)
                        st.erase({dis[newNode],newNode});
                    
                    dis[newNode] = wt + distance;
                    st.insert({dis[newNode],newNode});
                }
                
            }
        }
        return dis;
    }
};