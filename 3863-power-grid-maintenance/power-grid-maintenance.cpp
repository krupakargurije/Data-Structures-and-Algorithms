class Disjoint{
public:
    vector<int>par,sz;
    Disjoint(int n){
        sz.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int findpar(int u){
        if(par[u]==u) return u;
        return par[u]=findpar(par[u]);
    }
    void UnionBySize(int x,int y){
        int xp=findpar(x),yp=findpar(y);
        if(xp==yp) return;
        if(sz[xp]>sz[yp]){
            sz[xp]+=sz[yp];
            par[yp]=xp;
        }
        else{
            sz[yp]+=sz[xp];
            par[xp]=yp;
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        Disjoint dsu(c+1);
        for (auto& edge : connections) {
            dsu.UnionBySize(edge[0], edge[1]);
        }

        unordered_map<int, set<int>> online;
        for (int i=1; i<=c; ++i) {
            online[dsu.findpar(i)].insert(i);
        }

        vector<int> res;
        for (auto& q : queries) {
            int type=q[0], x=q[1];
            int root=dsu.findpar(x);
            if (type==1) {
                if (online[root].count(x)) res.push_back(x);
                else if (!online[root].empty()) res.push_back(*online[root].begin());
                else res.push_back(-1);
            } else {
                online[root].erase(x);
            }
        }
        return res;
    }
};