#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[n + 1];
        for (auto &i : edges) {
            int u = i[0], v = i[1], w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Undirected graph
        }

        // Step 2: Initialize distance and parent arrays
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        dist[1] = 0;

        // Step 3: Set stores {distance, node}
        set<pair<int, int>> st;
        st.insert({0, 1});

        // Step 4: Dijkstra's algorithm using set
        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(it);

            int curDist = it.first;
            int node = it.second;

            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;

                if (curDist + wt < dist[adjNode]) {
                    // If a shorter distance is found, update it
                    if (dist[adjNode] != INT_MAX)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = curDist + wt;
                    parent[adjNode] = node;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        // Step 5: If node n is not reachable
        if (dist[n] == INT_MAX)
            return {-1};

        // Step 6: Reconstruct path from n to 1
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        // Step 7: Return [total_weight, path...]
        vector<int> result;
        result.push_back(dist[n]);
        result.insert(result.end(), path.begin(), path.end());
        return result;
    }
};
