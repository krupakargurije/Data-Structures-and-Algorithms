class Solution {
    private:
    int helper(vector<vector<int>>& adj , int n){
        vector<int>vis(n , 0);
        int ans = 0;

        for(int i = 0;i<n;i++){
            if (vis[i]) continue;
            queue<int>q;

            q.push(i);
            vis[i] = 1;
            int vertices = 0, degree = 0;

            while(!q.empty()){
                auto node = q.front(); q.pop();

                vertices++;
                degree += adj[node].size();

                for (int nei : adj[node]) {
                    if (!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }

            int edgeCount = degree / 2;
            int requiredEdges = vertices * (vertices - 1) / 2;

            if (edgeCount == requiredEdges)
                ans++;
        }
        return ans;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int vertices = 0;
        int degree = 0;
        return helper(adj , n);
    }
};