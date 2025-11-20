class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Build graph
        for (auto &it : nums) {
            int u = it[0]; 
            int v = it[1];  
            adj[v].push_back(u);
            indeg[u]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        int vis = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis++;

            for (int it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }

        return vis == numCourses;
    }
};
