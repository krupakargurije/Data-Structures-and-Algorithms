class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans,vis(n,0),indegree(n,0);
        vector<vector<int>> adj(n);

        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        for(int i = 0;i<n;i++){
            for(auto node : adj[i]){
                indegree[node]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0)q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i] == 0)q.push(i);
            }
        }

        if(ans.size() == n)return ans;
        return {};
    }
};