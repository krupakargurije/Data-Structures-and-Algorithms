class Solution {
public:
    vector<vector<pair<int, int>>> gridToAdjList(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> adj(n * m);
        int delRow[] = {0, 1};
        int delCol[] = {1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u = i * m + j;
                for (int k = 0; k < 2; k++) {
                    int ni = i + delRow[k];
                    int nj = j + delCol[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        int v = ni * m + nj;
                        int w = grid[ni][nj];
                        adj[u].push_back({v, w});
                    }
                }
            }
        }
        return adj;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>> adj = gridToAdjList(grid);

        set<pair<int,int>> st;
        vector<int> dis(n*m,INT_MAX);
        dis[0] = grid[0][0];
        st.insert({dis[0],0});

        while(!st.empty()){
            auto it = *(st.begin());
            int d = it.first;
            int node = it.second;
            st.erase(it);

            for(auto& i : adj[node]){
                int adjNode = i.first;
                int wt = i.second;

                if(d + wt < dis[adjNode]){
                    if(dis[adjNode] != INT_MAX)st.erase({dis[adjNode],adjNode});
                    dis[adjNode] = d + wt;
                    st.insert({dis[adjNode],adjNode});
                }
            }
        }
        return dis[n*m -1];
    }
};