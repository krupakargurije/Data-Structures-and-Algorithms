class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& order) {
        if(order.empty())return true;
        int n = numCourses;

        vector<int>indegree(n , 0);
        vector<vector<int>>adj(n);

        for(auto &it : order){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        int vis = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            vis++;

            for(int i : adj[node]){
                indegree[i]--;
                if(!indegree[i])
                    q.push(i);
            }
        }
        return vis == n;
    }
};