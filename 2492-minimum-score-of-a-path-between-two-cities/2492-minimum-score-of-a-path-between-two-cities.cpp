class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &it : roads) {
            int a = it[0];
            int b = it[1];
            int dis = it[2];

            adj[a].push_back({b, dis});
            adj[b].push_back({a, dis});
        }

        queue<int> q;
        vector<int> vis(n + 1, 0);

        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &it : adj[node]) {
                ans = min(ans, it.second);

                if (!vis[it.first]) {
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
};