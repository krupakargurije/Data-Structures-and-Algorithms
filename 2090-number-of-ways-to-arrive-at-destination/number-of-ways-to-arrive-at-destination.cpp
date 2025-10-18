class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);

        int mod = 1e9 + 7;

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();

            if(dist > dis[node]) continue; // skip outdated entries

            for(auto it : adj[node]){
                int nNode = it.first;
                int eWt = it.second;

                if(dist + eWt < dis[nNode]){
                    dis[nNode] = dist + eWt;
                    pq.push({dis[nNode], nNode});
                    ways[nNode] = ways[node];
                }
                else if(dist + eWt == dis[nNode]){
                    ways[nNode] = (ways[nNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
