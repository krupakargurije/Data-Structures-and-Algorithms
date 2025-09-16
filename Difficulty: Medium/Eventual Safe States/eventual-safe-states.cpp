// User function Template for C++

class Solution {
  private:
    bool dfs(int node,vector<int>& vis,vector<int>& path,
    vector<int>& check,vector<int> adj[]){
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;
        
        for(auto i: adj[node]){
            if(!vis[i]){
                if(dfs(i,vis,path,check,adj) == true)return true;
            }else if(path[i])return true;
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> vis(n,0),path(n,0),check(n,0);
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,path,check,adj);
            }
        }
        vector<int> ans;
        
        for(int i = 0;i<n;i++){
            if(check[i] == 1)ans.push_back(i);
        }
        return ans;
    }
};
