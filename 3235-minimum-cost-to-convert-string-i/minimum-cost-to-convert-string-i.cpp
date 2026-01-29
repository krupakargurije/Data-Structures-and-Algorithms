class Solution {
public:
    const long long INF = 1e18;

    vector<long long> dijkstra(int src, vector<vector<pair<int,int>>>& adj) {
        vector<long long> dist(26, INF);

        //{currCost , currString}
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<pair<int,int>>> adj(26);
        for (int i = 0; i < original.size(); i++) {
            adj[original[i] - 'a'].push_back(
                {changed[i] - 'a', cost[i]}
            );
        }

        vector<vector<long long>> allDist(26);

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;

            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (allDist[s].empty())
                allDist[s] = dijkstra(s, adj);

            if (allDist[s][t] == INF) return -1;
            ans += allDist[s][t];
        }
        return ans;
    }
};
