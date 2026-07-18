class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<vector<int>>adj(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>q;
        vector<int>vis(n , 0);

        q.push(source);
        vis[source] = 1;

        while(!q.empty()){
            auto node = q.front(); q.pop();

            if(node == dest)return true;

            for(int i : adj[node]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return false;
    }
};