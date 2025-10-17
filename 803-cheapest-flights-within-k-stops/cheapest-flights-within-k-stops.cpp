class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dis(n,INT_MAX);

        // {stops,node,dis}
        q.push({0,{src,0}});
        dis[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k)continue;
            for(auto i : adj[node]){
                int nNode = i.first;
                int nCost = i.second;
                
                if(dis[nNode] > cost + nCost && stops <= k){
                    dis[nNode] = cost + nCost;
                    q.push({stops+1,{nNode,cost + nCost}});
                }
            }
        }

        if(dis[dst] == INT_MAX)return -1;
        return dis[dst];
    }
};