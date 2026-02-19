class Solution {
private:
    const int MOD = 1e9 + 7;

    int dfs(int node, int n,
            vector<vector<pair<int,int>>> &adj,
            vector<long long> &dis,
            vector<int> &dp){

        if(node == n) return 1;

        if(dp[node] != -1) return dp[node];

        long long ways = 0;

        for(auto &it : adj[node]){
            int nxt = it.first;

            if(dis[node] > dis[nxt]){
                ways = (ways + dfs(nxt, n, adj, dis, dp)) % MOD;
            }
        }

        return dp[node] = ways;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dis(n+1 , LLONG_MAX);

        dis[n] = 0;
        pq.push({0 , n});

        while(!pq.empty()){
            auto [d , node] = pq.top();
            pq.pop();

            if(d > dis[node]) continue;

            for(auto &it : adj[node]){
                int nxt = it.first;
                int w = it.second;

                if(d + w < dis[nxt]){
                    dis[nxt] = d + w;
                    pq.push({dis[nxt] , nxt});
                }
            }
        }
        vector<int> dp(n+1 , -1);
        return dfs(1 , n , adj , dis , dp);
    }
};