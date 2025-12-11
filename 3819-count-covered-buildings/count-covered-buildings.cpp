class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int>upperRow(n+1,n + 1),lowerRow(n+1,0);
        vector<int>upperCol(n+1,n + 1),lowerCol(n+1,0);

        for(auto it : buildings){
            int x = it[0];
            int y = it[1];

            upperRow[x] = min(upperRow[x],y);
            lowerRow[x] = max(lowerRow[x],y);

            upperCol[y] = min(upperCol[y], x);
            lowerCol[y] = max(lowerCol[y],x);
        }

        int ans = 0;
        for(auto b : buildings){
            int x = b[0];
            int y = b[1];
            if(upperRow[x] < y && y < lowerRow[x] && upperCol[y] < x && x < lowerCol[y]){
                ans++;
            }
        }
        return ans;
    }
};