class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n,vector<int>(n,1e8));

        for(auto it : edges){
            int src = it[0];
            int dst = it[1];
            int wt = it[2];
            adjMat[src][dst] = (wt);
            adjMat[dst][src] = (wt);
        }
        for(int i = 0;i<n;i++)adjMat[i][i] = 0;

        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j < n;j++){

                    if(adjMat[i][k] < 1e8 && adjMat[k][j] != 1e8 ){
                        adjMat[i][j] = min(adjMat[i][j],adjMat[i][k] + adjMat[k][j]);
                    }
                }
            }
        }

        int cityno = -1;
        int cityCnt = n;

        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j < n;j++){
                if(adjMat[i][j] <= distanceThreshold){
                    cnt++;
                }
            }

            if(cnt <= cityCnt){
                cityCnt = cnt;
                cityno = i;
            }
        }

        return cityno;
    }
};