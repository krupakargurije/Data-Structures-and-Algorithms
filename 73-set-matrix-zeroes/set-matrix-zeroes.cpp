class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> p;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0)p.push_back({i,j});
            }
        }

        for(auto num : p){
            int row = num.first;
            int col = num.second;

            for(int j = 0;j<n;j++){
                matrix[row][j] = 0;
            }
            for(int i = 0;i<m;i++){
                matrix[i][col] = 0;
            }
        }
    }
};