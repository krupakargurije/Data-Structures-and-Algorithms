class Solution {
  public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(auto i: edges){
            int u = i[0],v = i[1];
            adj[u].push_back(v);
        }
        vector<int> indegree(n,0);
        vector<int> vis(n,0);
        
        for(int i = 0;i<n;i++){
            for(auto el : adj[i]){
                indegree[el]++;
            }
        }
        
        queue<int> q;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
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
        return ans;
    }
};