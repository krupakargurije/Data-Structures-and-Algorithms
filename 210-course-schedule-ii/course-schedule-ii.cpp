class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>indegree(n , 0) , ans;
        vector<vector<int>>adj(n);

        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        for(int i = 0;i<n;i++){
            if(!indegree[i])
                q.push(i);
        }

        int vis = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            vis++;

            for(int i : adj[node]){
                indegree[i]--;
                if(!indegree[i])
                    q.push(i);
            }
        }
        if(vis != n)return {};
        return ans;
    }
};