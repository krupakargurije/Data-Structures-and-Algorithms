class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& path, vector<vector<int>>& adj) {
        vis[node] = 1;
        path[node] = 1;

        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, vis, path, adj)) return true;
            }
            else if (path[neigh]) {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

  public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0), path(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj)) return true;
            }
        }
        return false;
    }
};
