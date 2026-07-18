class UFDS{
    int n;
    vector<int>parents;

    public:
    UFDS(int n){
        this->n = n;
        parents.resize(n);

        for(int i = 0;i<n;i++){
            parents[i] = i;
        }
    }

    int find(int x){
        if(parents[x] == x)
            return x;
        return parents[x] = find(parents[x]);
    }

    bool unite(int x , int y){
        int px = find(x) , py = find(y);

        if(px == py)
            return false;
        
        parents[px] = py;
        return true;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int des) {
        UFDS ds(n);
        
        for(auto &e : edges){
            ds.unite(e[0], e[1]);
        }

        return ds.find(source) == ds.find(des);
    }
};

