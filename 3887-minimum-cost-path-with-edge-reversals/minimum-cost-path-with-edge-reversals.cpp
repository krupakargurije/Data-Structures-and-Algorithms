class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto it : edges){
            int u = it[0],v = it[1],w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,2 * w});
        }

        //{cost,node}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>>pq;

        vector<int>dis(n,INT_MAX);

        pq.push({0,0});
        dis[0] = 0;

        while(!pq.empty()){
            auto [cost , node] = pq.top();
            pq.pop();

            if(cost > dis[node])continue;

            for(auto [next , weight] : adj[node]){
                if(cost + weight < dis[next]){
                    dis[next] = cost + weight;
                    pq.push({cost + weight , next});
                }
            }
        }

        return (dis[n-1] == INT_MAX) ? -1 : dis[n-1];
    }
};