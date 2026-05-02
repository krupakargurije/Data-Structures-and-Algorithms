class Solution {
    private:
    vector<int> parent;

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unit(int x , int y){
        int px = find(x);
        int py = find(y);

        if(px == py)
            return false;
        
        parent[px] = py;
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);

        for(int i = 1;i<=n;i++)
            parent[i] = i;

        for(auto &it : edges){
            if(!unit(it[0] , it[1]))
                return it;
        }
        return {};
    }
}; 