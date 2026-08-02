class Solution {
    private:
    vector<int>parent;
    
    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x , int y){
        int px = find(x);
        int py = find(y);
        
        if(px == py)return false;
        parent[px] = py;
        return true;
    }
    
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        parent.resize(n);
        
        for(int i = 0;i<n;i++)parent[i] = i;
        
        for(auto &it : edges){
            if(unite(it[0] , it[1]))m--;
        }
        int builtEdges = (edges.size() - m) + 1;
        if(m >= n - builtEdges)
            return n - builtEdges;
        return -1;
    }
};