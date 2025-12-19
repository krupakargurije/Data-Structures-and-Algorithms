class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &m : meetings) {
            int x = m[0], y = m[1], t = m[2];
            adj[x].push_back({y, t});
            adj[y].push_back({x, t});
        }

        vector<int> time(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        time[0] = 0;
        time[firstPerson] = 0;

        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [curTime, u] = pq.top();
            pq.pop();

            if (curTime > time[u]) continue;

            for (auto &[v, t] : adj[u]) {
                if (t >= curTime && t < time[v]) {
                    time[v] = t;
                    pq.push({t, v});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (time[i] != INT_MAX) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
