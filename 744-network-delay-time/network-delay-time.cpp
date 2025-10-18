class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        vector<int> dis(n+1,INT_MAX);
        //{time,node}
        q.push({0,k});
        dis[k] = 0;

        while(!q.empty()){
            int time = q.top().first;
            int node = q.top().second;
            q.pop();

            for(auto it : adj[node]){
                int nNode = it.first;
                int eWt = it.second;

                if(eWt + time < dis[nNode]){
                    dis[nNode] = eWt + time;
                    q.push({eWt + time,nNode});
                    
                }
            }
        }
        
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(dis[i] == INT_MAX)return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};