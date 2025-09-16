class Solution {
private:
    bool dfs(int node,vector<int>& vis,vector<int>& path,vector<vector<int>>& adj){
        vis[node] = 1;
        path[node] = 1;

        for(auto i : adj[node]){
            if(!vis[i]){
               if(dfs(i,vis,path,adj))return true;
            }
            else if(path[i])return true;
        }
        path[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n,0),path(n,0);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,path,adj))return false;
            }
        }
        return true;
    }
};