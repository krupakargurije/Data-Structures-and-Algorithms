class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }

        // Min-heap: {cost, node, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, src, 0});

        vector<int> stopsArr(n, INT_MAX);
        stopsArr[src] = 0;

        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int cost = it[0];
            int node = it[1];
            int stop = it[2];

            if(node == dst) return cost;
            if(stop > k || stop > stopsArr[node]) continue;

            stopsArr[node] = stop;

            for(auto i : adj[node]){
                int nNode = i.first;
                int nCost = i.second;
                q.push({cost + nCost, nNode, stop + 1});
            }
        }

        return -1;
    }
};
