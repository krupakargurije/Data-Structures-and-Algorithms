class Disjoin{
    public:
    vector<int> range,parent;
    Disjoin(int n){
        range.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i<= n;i++){
            parent[i] = i;
        }
    }

    int findpr(int node){
        if(node == parent[node])return node;
        return parent[node] = findpr(parent[node]);
    }

    void unionByRange(int u,int v){
        int par_u = findpr(u);
        int par_v = findpr(v);

        if(par_u == par_v)return;

        if(range[par_u] < range[par_v]){
            parent[par_u] = par_v;
        }
        else if(range[par_u] > range[par_v]){
            parent[par_v] = par_u;
        }
        else{
            parent[par_u] = par_v;
            range[par_v]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Disjoin ds(n);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1)
                    ds.unionByRange(i,j);
            }
        }

        int count = 0;
        for(int i = 0;i<n;i++){
            if(ds.parent[i] == i)count++;
        }

        return count;
    }
};