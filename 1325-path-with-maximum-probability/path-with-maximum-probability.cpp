class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
    vector<double>& prob, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);

        for(int i = 0;i< edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v,prob[i]});
            adj[v].push_back({u,prob[i]});
        }

        vector<double>dis(n,0.0);
        // vector<int>vis(n,0);
        priority_queue<pair<double,int>>pq;

        pq.push({1.0,start});
        dis[start] = 1.0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            double wt = it.first;
            int nd = it.second;

            if(wt < dis[nd])continue;

            for(auto del : adj[nd]){
                double nwt = wt * del.second;
                int node = del.first;
                if(nwt > dis[node]){
                    dis[node] = nwt;
                    pq.push({dis[node] , node});
                }
            }
        }
        return dis[end];
    }
};




















