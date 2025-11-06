class Solution {
public:
     map<int,set<int>>mp;
     map<int,int>grid;

     void dfs(vector<vector<int>>&adj,int u,vector<bool>&visited,int component){
         visited[u] = true;
         mp[component].insert(u);
         grid[u] = component;

         for(auto& v:adj[u]){
            if(!visited[v]) dfs(adj,v,visited,component);
         }

         return;
     }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        set<int>st;
        vector<vector<int>>adj(c+1);

        for(auto &it:connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(c+1,false);

        int component = 0;

        for(int i=1;i<=c;i++){
            if(!visited[i]){
                dfs(adj,i,visited,component);
                component++;
            }
        }

        vector<int>ans;

        for(auto &q : queries){
            int node = q[1];
            int type = q[0];
            int comp = grid[node];
            if(type==2){
                mp[comp].erase(node);
                st.insert(node);
            }
            else{
               if(!st.count(node)) ans.push_back(node);
               else{
                   if(!mp[comp].empty()) ans.push_back(*mp[comp].begin());
                   else ans.push_back(-1);
               }
            }
        }

        return ans;

    }
};