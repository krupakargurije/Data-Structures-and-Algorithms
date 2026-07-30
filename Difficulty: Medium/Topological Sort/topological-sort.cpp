class Solution {
  public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<int>inDegree(n , 0);
        for(int i = 0;i<n;i++){
            for(int it : adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(!inDegree[i])
                q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int i : adj[node]){
                inDegree[i]--;
                if(inDegree[i] == 0)
                    q.push(i);
            }
            ans.push_back(node);
        }
        return ans;
    }
};