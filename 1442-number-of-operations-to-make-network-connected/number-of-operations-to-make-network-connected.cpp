class Disjoin{
    public:
    vector<int> range,parent;

    Disjoin(int n){
        range.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(node == parent[node])return node;

        return parent[node] = find(parent[node]);
    }

    void unionByRange(int u,int v){
        int par_u = parent[u];
        int par_v = parent[v];

        if(par_u == par_v)return;
        if(range[par_u] < range[par_v]){
            parent[par_u] = par_v;
        }
        else if(range[par_u] > range[par_v]){
            parent[par_v] = par_u;
        }
        else {
            parent[par_v] = par_u;
            range[par_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoin ds(n);
        int ext = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];

            if(ds.find(u) == ds.find(v))ext++;
            else ds.unionByRange(u,v);
        }

        int prov = 0;
        for(int i = 0;i<n;i++){
            if(ds.parent[i] == i)prov++;
        }

        return (prov - 1 <= ext) ? prov - 1 : -1;
    }
};