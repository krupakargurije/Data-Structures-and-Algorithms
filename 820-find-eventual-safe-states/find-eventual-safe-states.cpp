class Solution {
private:
    bool dfs(int start,vector<vector<int>>& graph,vector<int>& vis,
    vector<int>& path,vector<int>& check){
        vis[start] = 1;
        path[start] = 1;
        check[start] = 0;

        for(auto i: graph[start]){
            if(!vis[i]){
                if(dfs(i,graph,vis,path,check) == true){
                    check[start] = 0;
                    return true;
                }
            }
            else if(path[i]){
                check[start] = 0;
                return true;
            }
        }
        check[start] = 1;
        path[start] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> check(n,0);
        vector<int> ans;

        for(int i = 0;i<n;i++){
            dfs(i,graph,vis,path,check);
        }

        for(int i = 0;i<n;i++){
            if(check[i] == 1)ans.push_back(i);
        }
        return ans;
    }
};