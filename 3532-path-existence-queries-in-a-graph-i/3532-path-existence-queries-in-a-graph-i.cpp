class Solution {
    private:
    vector<int> parent, rank;

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.assign(n, 0);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        for(int i = 1;i<n;i++){
            if(nums[i] - nums[i - 1] <= maxDiff)
                unionByRank(i , i - 1);
        }

        vector<bool>ans;
        for(auto it : queries){
            if(parent[it[0]] ==  parent[it[1]])
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};