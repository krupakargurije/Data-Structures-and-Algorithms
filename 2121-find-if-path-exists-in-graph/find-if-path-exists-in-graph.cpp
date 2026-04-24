class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<vector<int>> adj(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n , 0);
        queue<int>q;
        q.push(source);
        vis[source] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == dest)return true;

            for(int it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};